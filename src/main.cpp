#include <storage/Storage.h>
#include "../include/commandParser/ComandParser.h"
#include "../include/executor/BucketExecutor.h"

int main() {
    Storage storage;
    BucketExecutor bucket_executor;
    ComandParser commandParser(storage, bucket_executor);

    std::string cmd;
    while (std::getline(std::cin, cmd)) {
        commandParser.parse(cmd);
    }

    return 0;
}
