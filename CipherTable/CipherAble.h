#include <string>

#ifndef CIPHERABLE_H
#define CIPHERABLE_H

class CipherAble {
    virtual std::string find_encrypted_letter_by_key(std::string letter, std::string key) = 0;
    virtual void init() = 0;
    virtual void to_string() = 0;
};

#endif //CIPHERABLE_H
