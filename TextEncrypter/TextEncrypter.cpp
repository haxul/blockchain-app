#include <regex>
#include "TextEncrypter.h"
#include "../Key/Key.h"
#include "../CipherTable/CipherTable.h"

using namespace std;

TextEncrypter::TextEncrypter(string text, Key *key_init) {
    init_text = new string(text);
    key = key_init;
}

TextEncrypter::~TextEncrypter() {
    delete init_text;
    delete key;
}

void TextEncrypter::remove_init_text_spaces() {
    regex reg_exp("\\s+");
    *init_text = regex_replace(*init_text, reg_exp, "");
}

string TextEncrypter::encrypt() {
    remove_init_text_spaces();
    auto vigenere_table = make_unique<CipherTable>();
    string encrypted_text = "";
    int text_length = init_text->size();
    string filled_key =  key->fill_text_by_key(text_length);
    for (int i = 0; i < init_text->size(); ++i) {
        string character = string(1,init_text->at(i));
        bool isLetter = regex_match(character, regex("[a-zA-Z]"));
        if (isLetter) {
            string cur_key_letter = string(1, tolower(filled_key.at(i)));
            string value = vigenere_table->find_encrypted_letter_by_key(character, cur_key_letter);
            encrypted_text += value.empty() ? cur_key_letter : value;
            continue;
        }
        encrypted_text += character;
    }
    return encrypted_text;
}