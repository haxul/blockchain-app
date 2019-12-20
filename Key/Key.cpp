#include <iostream>
#include "Key.h"
#include "string"

using namespace std;

Key::Key(string key_value) {
    this->key_value = new string(key_value);
}

Key::~Key() {
    delete key_value;
}
/*
 * method to create string of repeated key
 * for example:
 *  text_length == 9
 *  key_value = lemon
 *  method return string `lemonlemo` (9 letters)
 * */
string Key::fill_text_by_key(unsigned int text_length) {
    string result = "";
    int key_letter_index = 0;
    for (int i = 0; ; ++i) {
        if (result.size() >= text_length) return result;
        if (key_letter_index >= key_value->size()) key_letter_index = 0;
        result += key_value->at(key_letter_index);
        key_letter_index++;
    }
}

string Key::get_key() {
    return *key_value;
}
