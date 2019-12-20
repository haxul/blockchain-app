#include <iostream>
#include "./Key/Key.h"
#include "./TextEncrypter/TextEncrypter.h"
#include "./Menu/Menu.h"
#include "./Helpers/throw_message.h"
#include <memory>

using namespace std;

int main() {
    auto menu = make_unique<Menu>();
    menu->open();
    string raw_text = menu->get_text();
    if (raw_text == "") throw_message("file is not found");
    string key_text = menu->get_key();
    Key *encrypt_key = new Key(key_text);
    auto encrypter = make_unique<TextEncrypter>(raw_text, encrypt_key);
    cout << encrypter->encrypt();
    return 0;
}
