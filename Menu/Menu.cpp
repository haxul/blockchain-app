#include "Menu.h"
#include <iostream>
#include <regex>

#define AMOUNT_CHARS 32767
#define ENTER_TEXT_MANUALLY 0
#define INPUT_FILE_TEXT 1
using namespace std;

void Menu::open() {
    cout << "Hello, please choose how do you want to enter text data?" << endl;
    cout << "0. Enter text manually by keyboard" << endl;
    cout << "1. Enter text by existed file" << endl;
}

unsigned int Menu::choose_option_to_input_text() {
    while (true) {
        unsigned int choosen_option;
        cin >> choosen_option;
        bool isCorrectCommand = choosen_option == INPUT_FILE_TEXT || choosen_option == ENTER_TEXT_MANUALLY;
        bool isCorrectEnter = !cin.fail() && isCorrectCommand;
        if (isCorrectEnter) return choosen_option;
        cout << "Unknown command, please try again:" << endl;
        std::cin.clear();
        std::cin.ignore(AMOUNT_CHARS, '\n');
    }
}

string Menu::enter_text(const string message) {
    cout << message << endl;
    cin.ignore();
    string text;
    getline(cin, text);
    return text;
}

string Menu::input_file()   {
    //TODO
    return "file";
}

string Menu::get_key() {
    while (true) {
        string key = enter_text("enter key (only lowered letters): ");
        regex english_letters("^[a-z]+$");
        if (regex_match(key, english_letters)) return key;
        cout << "error" << endl;
    }
}

string Menu::get_text() {
    unsigned int choosed_option = choose_option_to_input_text();
    return choosed_option == ENTER_TEXT_MANUALLY ? enter_text("enter text to be encrypted: ") : input_file();
}