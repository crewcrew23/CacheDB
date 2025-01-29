#ifndef LOGER_H
#define LOGER_H

#include <iostream>
#include <string_view>

class Logger {
public:
    static void log(const std::string_view message){
        std::clog << message << std::endl;
    }

    static void log(const std::string_view message, const std::string_view param){
        std::clog << message << param << std::endl;
    }
};

#endif //LOGER_H
