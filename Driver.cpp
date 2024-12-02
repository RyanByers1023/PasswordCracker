#include <iostream>

#include "FileLoader.h"
#include "PasswordCracker.h"

int main() {
    FileLoader fileLoader;
    PasswordCracker passwordCracker;

    auto hashes = fileLoader.loadHashes("passwords.txt");
    auto dictionary = fileLoader.loadDictionary("dictionary.txt");

    passwordCracker.crackPasswords(hashes, dictionary);

    return 0;
}