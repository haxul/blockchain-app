#include <iostream>
#include "./Key/Key.h"
#include "./TextEncrypter/TextEncrypter.h"
#include <memory>

using namespace std;
int main() {
    //TODO menu
    Key *key = new Key("lemon");
    auto text_encrypter = make_unique<TextEncrypter>("hello    8world", key);
    cout << text_encrypter->encrypt();
    return 0;
}
