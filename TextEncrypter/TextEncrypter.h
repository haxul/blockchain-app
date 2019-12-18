
#include <string>
#include "../Key/Key.h"

using namespace std;
class TextEncrypter {
private:
    string* init_text;
    Key* key;
    void remove_init_text_spaces();
public:
    string encrypt();
    TextEncrypter(string , Key*);
    ~TextEncrypter();
    string get_init_text();
};

