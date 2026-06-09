#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include <string>
class IOHandler {
    public:
        static std::string readLine(const std::string& prompt);
        static void write(const std::string& message);
};

#endif