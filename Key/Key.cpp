#include "Key.h"
#include "string"

using namespace std;

Key::Key(string key_value) {
    value = new string(key_value);
}

Key::~Key() {
    delete value;
}

string Key::fill_text_by_key(int size) {
    string result = "";
    for (int i = 0; i < size ; ++i) {

    }
    return reinterpret_cast<basic_string<char, char_traits<char>, allocator<char>> &&>((*value)[0]);
}
