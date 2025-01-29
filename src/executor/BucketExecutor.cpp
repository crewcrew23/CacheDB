#include "../../include/executor/BucketExecutor.h"

void BucketExecutor::execute(const std::string& cmd, const std::string& bucketName, Storage& storage) {
    try {
        if (cmd == "CREATE") {
            bool status = storage.create_bucket(bucketName);
            logger_.log("Created bucket status: " + std::to_string(status));
        } else if (cmd == "DELETE") {
            bool status = storage.delete_bucket(bucketName);
            logger_.log("Delete bucket status: " + std::to_string(status));
        } else if (cmd == "USE") {
            bool status = storage.use_bucket(bucketName);
            logger_.log("Use bucket status: " + std::to_string(status));
        }
    }catch (std::exception& e) {
        logger_.log(std::string("Exception: ") + e.what());
    }
}
