#include "CommandParser.h"
#include <sstream>

ParsedCommand CommandParser::parse(const std::string& input) {
    ParsedCommand cmd; 
    std::stringstream ss(input); 
    std::string word;
    
    if (ss >> word) { 
        cmd.name = word; 
        while (ss >> word) { 
            cmd.args.push_back(word); 
        } 
    }
    
    return cmd;
}