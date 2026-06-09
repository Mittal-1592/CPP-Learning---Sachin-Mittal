#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "ParsedCommand.h"
#include "FileSystem.h"

class CommandHandler {
    private:
        FileSystem& fileSystem;

        void help() const;
        bool makeDir(const std::string& path);
        bool makeFile(const std::string& path);
        bool rm(const std::string& path, const std::vector<std::string>& args);
        void find(const std::vector<std::string>& args);
        void cat(const std::vector<std::string>& args);
        void echo(const std::vector<std::string>& args);
        void pwd() const;
        
    public:
        explicit CommandHandler(FileSystem& fileSystem);
        bool execute(const ParsedCommand& parsedCommand);
};

#endif