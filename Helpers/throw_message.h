
#ifndef THROW_MESSAGE_H
#define THROW_MESSAGE_H

#include <string>
#include <iostream>
#define OK 1
void throw_message(std::string message) {
    std::cout << message << std::endl;
    exit(OK);
}
#endif //THROW_MESSAGE_H
