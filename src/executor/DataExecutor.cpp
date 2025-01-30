#include "../../include/executor/DataExecutor.h"

void DataExecutor::execute(const std::string& cmd, Storage& storage, const long& key, const std::string& value) {
    try {
        if (cmd == "SEY") {
            bool status = storage.set(key, value);
            logger_.log("SET bucket value status: " + std::to_string(status));
        } else if (cmd == "GET") {
            auto status = storage.get(key);
        } else if (cmd == "DEL") {
            bool status = storage.del(key);
            logger_.log("DEL bucket value status: " + std::to_string(status));
        }
    }catch (std::exception& e) {
        logger_.log(std::string("Exception: ") + e.what());
    }
}
