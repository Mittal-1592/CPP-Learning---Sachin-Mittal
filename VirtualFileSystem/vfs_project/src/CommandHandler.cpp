#include "CommandHandler.h"
#include <iostream>
#include <iomanip>

CommandHandler::CommandHandler(FileSystem& fileSystem) : fileSystem(fileSystem) {}

void CommandHandler::pwd() const {
    std::cout << fileSystem.getCurrentPath() << "\n";
}

void CommandHandler::help() const {
    std::cout << "\nAvailable Commands:\n\n";

    std::cout << "mkdir <dir>        Create directory\n";
    std::cout << "touch <file>       Create file\n";
    std::cout << "cd <path>          Change directory\n";
    std::cout << "ls                 List current directory\n";
    std::cout << "pwd                Print current directory\n";
    std::cout << "rm <file>          Remove file\n";
    std::cout << "rm -r <dir>        Remove directory recursively\n";
    std::cout << "cat <file>         Display file contents\n";
    std::cout << "echo <text>        Print text\n";
    std::cout << "echo <text> > f    Write text to file\n";
    std::cout << "echo <text> >> f   Append text to file\n";
    std::cout << "find -name <n>     Find by name\n";
    std::cout << "find -size a b     Find by size range\n";
    std::cout << "find -content txt  Find by content\n";
    std::cout << "find -timestamp s e Find by timestamp range\n";
    std::cout << "help               Show this help menu\n";
    std::cout << "exit               Exit VFS\n\n";
}

bool CommandHandler::makeDir(const std::string& path) { 
    return fileSystem.createDir(path); 
}

bool CommandHandler::makeFile(const std::string& path) { 
    return fileSystem.createFile(path); 
}

bool CommandHandler::rm(const std::string& path, const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "rm: missing operand\n";
        return false;
    }

    if (args[0] == "-r") {
        if (args.size() < 2) {
            std::cerr << "rm: missing operand after '-r'\n";
            return false;
        }
        
        std::string targetPath = args[1];
        bool success = fileSystem.removeDir(targetPath);
        
        if (!success) {
            success = fileSystem.removeFile(targetPath);
        }
        
        if (!success) {
            std::cerr << "rm: cannot remove '" << targetPath << "': No such file or directory\n";
        }
        return success;
    }

    bool success = fileSystem.removeFile(path);
    
    if (!success) {
        if (fileSystem.changeDir(path)) {
            std::cerr << "rm: cannot remove '" << path << "': Is a directory\n";
            fileSystem.changeDir("..");
            return false;
        }
        
        std::cerr << "rm: cannot remove '" << path << "': No such file or directory\n";
    }
    return success;
}

void CommandHandler::find(const std::vector<std::string>& args) {
    if (args.empty()) {
        return;
    }

    std::vector<std::shared_ptr<FileSystemComponent>> results;
    
    if (args[0] == "-name" && args.size() > 1) {
        results = fileSystem.findByName(args[1]);
    } 
    else if (args[0] == "-size" && args.size() > 2) {
        results = fileSystem.findBySize(std::stoull(args[1]), std::stoull(args[2]));
    } 
    else if (args[0] == "-content" && args.size() > 1) {
        results = fileSystem.findByContent(args[1]);
    }
    else if (args[0] == "-timestamp" && args.size() > 2) {
        std::string startStr = args[1];
        std::string endStr = args[2];

        std::tm tmStart = {}, tmEnd = {};
        std::stringstream ssStart(startStr), ssEnd(endStr);

        ssStart >> std::get_time(&tmStart, "%Y-%m-%d_%H:%M:%S");
        ssEnd >> std::get_time(&tmEnd, "%Y-%m-%d_%H:%M:%S");

        if (ssStart.fail() || ssEnd.fail()) {
            std::cerr << "find: Invalid time format. Please use YYYY-MM-DD_HH:MM:SS\n"
                      << "Example: find -timestamp 2026-06-08_11:00:00 2026-06-08_12:00:00\n";
            return;
        }

        std::time_t startTime = std::mktime(&tmStart);
        std::time_t endTime = std::mktime(&tmEnd);

        results = fileSystem.findByTimestamp(startTime, endTime);
    }
    if (results.empty()) {
        std::cout << "No matching files or directories found.\n";
        return;
    }
    for (const auto& item : results) { 
        std::cout << (item->getComponentType() == FileSystemComponentType::Directory ? "[DIR] " : "[FILE] ") 
                  << item->getName() << "\n"; 
    }
}

void CommandHandler::cat(const std::vector<std::string>& args) { 
    if (!args.empty()) {
        std::cout << fileSystem.readFile(args[0]) << "\n"; 
    }
    else{
        std::cerr << "cat: missing file operand\nTry 'help' for more information.\n";
    }
}

void CommandHandler::echo(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cout << "\n";
        return;
    }

    std::string combinedText = "";
    std::string redirectOperator = "";
    std::string targetFileName = "";
    
    size_t operatorIndex = std::string::npos;

    for (size_t i = 0; i < args.size(); ++i) {
        if (args[i] == ">" || args[i] == ">>") {
            redirectOperator = args[i];
            operatorIndex = i;
            break;
        }
    }

    if (operatorIndex != std::string::npos) {
        if (operatorIndex + 1 >= args.size()) {
            std::cerr << "vfs: echo: syntax error near unexpected token 'newline'\n";
            return;
        }

        targetFileName = args[operatorIndex + 1];

        for (size_t i = 0; i < operatorIndex; ++i) {
            combinedText += args[i];
            if (i + 1 < operatorIndex) {
                combinedText += " "; 
            }
        }

        if (redirectOperator == ">") {
            fileSystem.writeFile(targetFileName, combinedText);
        } else if (redirectOperator == ">>") {
            fileSystem.appendToFile(targetFileName, combinedText);
        }
    } 
    else {
        for (size_t i = 0; i < args.size(); ++i) {
            std::cout << args[i];
            if (i + 1 < args.size()) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

bool CommandHandler::execute(const ParsedCommand& parsedCommand) {
    std::string command = parsedCommand.name; 
    auto args = parsedCommand.args;

    if (command == "exit") {
        return false;
    }
    
    if (command == "mkdir") {
        if (args.empty()) {
            std::cerr << "mkdir: missing operand\nTry 'mkdir --help' for more information.\n";
        } 
        else {
            for (const auto& dirName : args) {
                makeDir(dirName);
            }
        }
    } 
    else if (command == "touch") {
        if (args.empty()) {
            std::cerr << "touch: missing file operand\nTry 'touch --help' for more information.\n";
        } 
        else {
            for (const auto& fileName : args) {
                makeFile(fileName);
            }
        }
    }
    else if (command == "cd") {
        std::string targetPath = args.empty() ? "/" : args[0];
        if (!fileSystem.changeDir(targetPath)) {
            std::cerr << "vfs: cd: " << targetPath << ": No such file or directory\n";
        }
    }
    else if (command == "ls") {
        fileSystem.listCurrentDirectory();
    } 
    else if (command == "rm") {
        rm(args[0], args);
    }
    else if (command == "cat") {
        cat(args);
    } 
    else if (command == "echo") {
        echo(args);
    } 
    else if (command == "pwd") {
        pwd();
    }
    else if (command == "find") {
        find(args);
    }
    else if (command == "help") {
        help();
    }
    else {
        std::cerr << "vfs: " << command << ": command not found\n";
    }
    
    return true;
}