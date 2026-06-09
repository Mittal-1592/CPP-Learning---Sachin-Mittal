#include "IOHandler.h"
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

std::string IOHandler::readLine(const std::string& prompt) {
    char* input = readline(prompt.c_str()); 
    if (!input) {
        return "";
    }
    
    std::string line(input);
    if (!line.empty()) {
        add_history(input); 
    }
    
    free(input); 
    return line;
}

void IOHandler::write(const std::string& message) {
    std::cout << message << std::flush;
}