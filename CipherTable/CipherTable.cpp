
#include <ostream>
#include "CipherTable.h"

#define ALPHABET_SIZE 26

std::string CipherTable::alphabet[ALPHABET_SIZE] = {
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

int **CipherTable::create_rows() {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        matrix[i] = new int[ALPHABET_SIZE];
    }
    return matrix;
}

void CipherTable::init() {
    matrix = create_rows();
    int cell = 0;
    for (int column = 0; column < ALPHABET_SIZE; ++column) {
        for (int row = 0; row < ALPHABET_SIZE; ++row) {
            if (cell > ALPHABET_SIZE - 1) cell = 0;
            matrix[column][row] = cell++;
        }
        int indent = column + 1;
        cell = indent;
    }
}

void CipherTable::to_string() {
    for (int column = 0; column < ALPHABET_SIZE; ++column) {
        for (int row = 0; row < ALPHABET_SIZE; ++row) {
            std::cout << this->matrix[column][row] << " ";
        }
        std::cout << std::endl;
    }
}
