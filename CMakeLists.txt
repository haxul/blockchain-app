cmake_minimum_required(VERSION 3.15)
project(blockchain_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain_game main.cpp CipherTable/CipherTable.cpp CipherTable/CipherTable.h CipherTable/CipherAble.h Key/Key.cpp Key/Key.h TextEncrypter/TextEncrypter.cpp TextEncrypter/TextEncrypter.h Menu/Menu.cpp Menu/Menu.h)