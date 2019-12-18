
#ifndef KEY_H
#define KEY_H

#include "string"

class Key {
public:
    Key(std::string key_value) ;
    ~Key();
    std::string fill_text_by_key(int size);

private:
    std::string* value;
};


#endif KEY_H
