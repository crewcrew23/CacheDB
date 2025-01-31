#ifndef DATAEXECUTOR_H
#define DATAEXECUTOR_H

#include <string>
#include "../storage/Storage.h"
#include "../logger/Logger.h"
#include "../commandParser/data_comand.h"

class DataExecutor {
public:
    Logger logger_;
    data_command::DATA_COMMAND command_;
    void execute(const std::string& cmd, Storage& storage, const long& key, const std::string& value = "");

    DataExecutor() = default;
    ~DataExecutor() = default;
};

#endif //DATAEXECUTOR_H