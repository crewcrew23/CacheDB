#ifndef COMANDPARSER_H
#define COMANDPARSER_H

#include <sstream>
#include <vector>
#include <logger/Logger.h>

#include "bucket_command.h"
#include "data_comand.h"
#include "../storage/Storage.h"
#include "../executor/BucketExecutor.h"

class ComandParser {
private:
    Logger logger_;
    BucketExecutor& bucket_executor_;
    Storage& storage_;

    std::vector<std::string> splitCommand(const std::string& command) const;
    bool isBucketCommand(const std::string& cmd) const;
    bool isDataCommand(const std::string& cmd) const;

public:
    ComandParser(Storage& storage, BucketExecutor& bucket_executor) : storage_(storage), bucket_executor_(bucket_executor) {}
    void parse(const std::string& command) const;
};
#endif //COMANDPARSER_H
