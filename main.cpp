#include <iostream>
#include "./CipherTable/CipherTable.h"
#include "./Key/Key.h"
#include <memory>
int main() {
    auto vigenere_table = std::make_unique<CipherTable>();
    Key key("lemon");
    std::cout << key.fill_text_by_key(6);
    return 0;
}
