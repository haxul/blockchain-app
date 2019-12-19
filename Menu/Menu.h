#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class Menu {
private:
    unsigned int choose_option_to_input_text();
    string enter_text(const string message);
    string input_file();
public:
    void open();
    string get_key();
    string get_text();
};


#endif //MENU_H
