#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "ParsedCommand.h"
class CommandParser {
    public:
        static ParsedCommand parse(const std::string& input);
};

#endif
