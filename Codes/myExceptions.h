#ifndef MY_EXCEPTIONS_H
#define MY_EXCEPTIONS_H

#include <string>
#include <exception>

class illegalParameterValue : public std::exception {
public:
    illegalParameterValue(const std::string& message = "Illegal parameter value") {
        this->message = message;
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};

#endif
