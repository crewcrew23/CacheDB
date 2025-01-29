#ifndef BUCKET_COMMAND_H
#define BUCKET_COMMAND_H

#include <string>
#include <unordered_map>

namespace bucket_command {
    enum class BUCKET_COMMAND { CREATE, DELETE, USE };

    static const std::unordered_map<std::string, BUCKET_COMMAND> stringToCommand = {
        {"CREATE", BUCKET_COMMAND::CREATE},
        {"DELETE", BUCKET_COMMAND::DELETE},
        {"USE", BUCKET_COMMAND::USE}
    };

    static const std::unordered_map<BUCKET_COMMAND, std::string> commandToString = {
        {BUCKET_COMMAND::CREATE, "CREATE"},
        {BUCKET_COMMAND::DELETE, "DELETE"},
        {BUCKET_COMMAND::USE, "USE"}
    };
}

#endif //BUCKET_COMMAND_H
