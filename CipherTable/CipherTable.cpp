
#include <ostream>
#include "CipherTable.h"

#define ALPHABET_SIZE 26
using namespace std;
std::array<string, ALPHABET_SIZE> CipherTable::alphabet = {
        "a", "b", "c", "d", "e", "f", "g",
        "h", "i", "j", "k", "l", "m", "n",
        "o", "p", "q", "r", "s", "t", "u",
        "v", "w", "x", "y", "z"
};

CipherTable::CipherTable() {
    init();
}

CipherTable::~CipherTable() {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void CipherTable::create_rows() {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        matrix[i] = new int[ALPHABET_SIZE];
    }
}

void CipherTable::init() {
    create_rows();
    int cell = 0;
    for (int column = 0; column < ALPHABET_SIZE; ++column) {
        for (int row = 0; row < ALPHABET_SIZE; ++row) {
            if (cell > ALPHABET_SIZE - 1) cell = 0;
            matrix[column][row] = cell++;
        }
        int shift = column + 1;
        cell = shift;
    }
}

int get_index(const array<string, ALPHABET_SIZE> &list, string element)
{
    for (int i = 0; i < list.size(); ++i) {
        if (element == list.at(i)) return i;
    }
    return -1;
}

std::string CipherTable::find_encrypted_letter_by_key(std::string letter, std::string key) {
    int letter_index = get_index(alphabet, letter);
    int key_index = get_index(alphabet, key);
    if (letter_index == -1 || key_index == -1) return "";
    int found_letter_index  = this->matrix[letter_index][key_index];
    return alphabet[found_letter_index];
}

void CipherTable::to_string() {
    for (int column = 0; column < ALPHABET_SIZE; ++column) {
        for (int row = 0; row < ALPHABET_SIZE; ++row) {
            std::cout << this->matrix[column][row] << " ";
        }
        std::cout << std::endl;
    }
}
