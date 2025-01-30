#include "../include/commandParser/ComandParser.h"

std::vector<std::string> ComandParser::splitCommand(const std::string& command) const {
    std::vector<std::string> tokens;
    std::istringstream iss(command);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

bool ComandParser::isDataCommand(const std::string& cmd) const {
    return data_command::stringToCommand.find(cmd) != data_command::stringToCommand.end();
}

bool ComandParser::isBucketCommand(const std::string& cmd) const {
    return bucket_command::stringToCommand.find(cmd) != bucket_command::stringToCommand.end();
}

void ComandParser::parse(const std::string& command) const{
    logger_.log("Command Parsing: ", command);
    auto tokens = splitCommand(command);

    if (tokens.empty()) {
        logger_.log("Error: Empty command");
        return;
    }

    if (tokens[0] == "LIST") {
        logger_.log("Executing LIST command");
        return;
    }

    if (isBucketCommand(tokens[0])) {
        if (tokens.size() != 2) {
            logger_.log("Error: Invalid bucket command format");
            return;
        }
        bucket_command::BUCKET_COMMAND cmd = bucket_command::stringToCommand.at(tokens[0]);
        std::string bucketName = tokens[1];
        logger_.log("Executing bucket command: " + bucket_command::commandToString.at(cmd) + " " + bucketName);
        std::string cmd_string = bucket_command::commandToString.at(cmd);
        bucket_executor_.execute(cmd_string, bucketName, storage_);
        return;
    }

    if (isDataCommand(tokens[0])) {
        if (tokens.size() < 3) {
            logger_.log("Error: Invalid data command format");
            return;
        }
        data_command::DATA_COMMAND cmd = data_command::stringToCommand.at(tokens[0]);
        std::string key, value;
        for (size_t i = 1; i < tokens.size(); i += 2) {
            if (tokens[i] == "-k" || tokens[i] == "--key") {
                if (i + 1 < tokens.size()) key = tokens[i + 1];
            } else if (tokens[i] == "-v" || tokens[i] == "--value") {
                if (i + 1 < tokens.size()) value = tokens[i + 1];
            }
        }
        logger_.log("Executing data command: " + data_command::commandToString.at(cmd) + " Key: " + key + " Value: " + value);
        std::string cmd_string = data_command::commandToString.at(cmd);
        long key_long = std::stol(key);
        data_executor_.execute(cmd_string, storage_, key_long, value);
        return;
    }

    logger_.log("Error: Unknown command");

}
