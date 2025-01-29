#ifndef BUCKETEXECUTOR_H
#define BUCKETEXECUTOR_H

#include <string>
#include "../storage/Storage.h"
#include "../logger/Logger.h"

class BucketExecutor {
public:
    Logger logger_;
    void execute(const std::string& cmd, const std::string& bucketName, Storage& storage);

    BucketExecutor() = default;
    ~BucketExecutor() = default;
};

#endif //BUCKETEXECUTOR_H
