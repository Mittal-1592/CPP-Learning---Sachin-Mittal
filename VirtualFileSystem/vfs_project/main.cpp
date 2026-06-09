#include <memory>
#include "FileSystem.h"
#include "CommandHandler.h"
#include "CommandParser.h"
#include "IOHandler.h"

int main() {
    auto fileSystem = std::make_unique<FileSystem>(); 
    auto handler = std::make_unique<CommandHandler>(*fileSystem);
    auto parser = std::make_unique<CommandParser>();
    auto ioHandler = std::make_unique<IOHandler>();

    ioHandler->write("========================================================\n");
    ioHandler->write("    Simulation Linux Environment Up & Running (VFS)     \n");
    ioHandler->write("========================================================\n");

    bool running = true;
    while (running) {
        std::string prompt = "vfs@linux-sim:" + fileSystem->getCurrentPath() + "$ ";
        std::string input = ioHandler->readLine(prompt);
        ParsedCommand cmd = parser->parse(input);
        running = handler->execute(cmd);
    }
    return 0;
}