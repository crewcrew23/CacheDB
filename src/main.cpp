#include <storage/Storage.h>
#include "../include/commandParser/ComandParser.h"
#include "../include/executor/BucketExecutor.h"
#include "../include/executor/DataExecutor.h"

int main() {
    Storage storage;
    BucketExecutor bucket_executor;
    DataExecutor data_executor;
    ComandParser commandParser(storage, bucket_executor, data_executor);

    std::string cmd;
    while (std::getline(std::cin, cmd)) {
        commandParser.parse(cmd);
    }

    return 0;
}
