#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <exception>
#include <stdexcept>
#include <string>

class DataBaseException : public std::runtime_error {
public:
    explicit DataBaseException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // DATABASEEXCEPTION_H