#ifndef PARSED_COMMAND_H
#define PARSED_COMMAND_H

#include <string>
#include <vector>

class ParsedCommand {
    public:
        std::string name;
        std::vector<std::string> args;
};

#endif