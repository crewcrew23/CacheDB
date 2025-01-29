#ifndef DATA_COMMAND_H
#define DATA_COMMAND_H

#include <string>
#include <unordered_map>

namespace data_command {
    enum class DATA_COMMAND { SET, GET, DEL };

    static const std::unordered_map<std::string, DATA_COMMAND> stringToCommand = {
        {"SET", DATA_COMMAND::SET},
        {"GET", DATA_COMMAND::GET},
        {"DEL", DATA_COMMAND::DEL}
    };

    static const std::unordered_map<DATA_COMMAND, std::string> commandToString = {
        {DATA_COMMAND::SET, "SET"},
        {DATA_COMMAND::GET, "GET"},
        {DATA_COMMAND::DEL, "DEL"}
    };
}

#endif // DATA_COMMAND_H