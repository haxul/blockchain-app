#include "Key.h"
#include "string"

using namespace std;

Key::Key(string key_value) {
    value = new string(key_value);
}

Key::~Key() {
    delete value;
}

string Key::fill_text_by_key(const string &text) {
    string result = "";
    //TODO function to fill text reuesable key
    return "test";
}
