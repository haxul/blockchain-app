#include <iostream>
#include "./CipherTable/CipherTable.h"

int main() {
    CipherTable table;
    std::cout << table.encrypt_letter_by_key("d", "f") << std::endl;
    table.to_string();
    return 0;
}
