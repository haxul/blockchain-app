
#ifndef CIPHERTABLE_H
#define CIPHERTABLE_H

#include <string>
#include <iostream>
#include "CipherAble.h"
#define ALPHABET_SIZE 26

class CipherTable : public CipherAble {
public:
    CipherTable();
    ~CipherTable();
    static std::string alphabet[ALPHABET_SIZE];
    std::string encrypt_letter_by_key(std::string letter, std::string key);
    void to_string();
private:
    void init();
    int** matrix = new int*[ALPHABET_SIZE] {0};
    int** create_rows();
 };


#endif //CIPHERTABLE_H
