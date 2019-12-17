
#ifndef CIPHERTABLE_H
#define CIPHERTABLE_H

#include <string>
#include <iostream>
#include "CipherAble.h"
#include <array>
#include <vector>

#define ALPHABET_SIZE 26

class CipherTable : public CipherAble {
public:
    CipherTable();
    ~CipherTable();
    static std::array<std::string, ALPHABET_SIZE> alphabet;
    std::string encrypt_letter_by_key(std::string letter, std::string key) override ;
    void to_string() override ;
private:
    void init() override ;
    int** matrix = new int*[ALPHABET_SIZE] {0};
    void create_rows();
 };


#endif //CIPHERTABLE_H
