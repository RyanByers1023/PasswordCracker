#include "PasswordCracker.h"

void PasswordCracker::crackPasswords(const std::unordered_map<std::string, std::string>& hashes, const std::vector<std::string>& dictionary) {
    HashHandler hashCalculator;

    //test for a digit-only password: (up to 99999999)
    guessDigitsOnly(hashCalculator, hashes);

    //test for a word-only password: (from dictionary.txt)
    guessWordsOnly(hashCalculator, hashes, dictionary);
    
    //test for a password with both numbers and words:
    guessWordsAndDigits(hashCalculator, hashes, dictionary);
}

void PasswordCracker::guessDigitsOnly(HashHandler& hashCalculator, const std::unordered_map<std::string, std::string>& hashes) {
    for (int i = 0; i <= 99999999; ++i) {
        std::string guess = std::to_string(i);
        std::string hash = hashCalculator.computeHash(guess);
        auto it = hashes.find(hash);
        if (it != hashes.end()) {
            std::cout << "Cracked! ID: " << it->second << ", Password: " << guess << std::endl;
        }
    }
}

void PasswordCracker::guessWordsOnly(HashHandler& hashCalculator, const std::unordered_map<std::string, std::string>& hashes, const std::vector<std::string>& dictionary) {
    for (const auto& word : dictionary) {
        std::string hash = hashCalculator.computeHash(word);
        auto it = hashes.find(hash);
        if (it != hashes.end()) {
            std::cout << "Cracked! ID: " << it->second << ", Password: " << word << std::endl;
        }
    }

    //check concatenated words
    for (const auto& word1 : dictionary) {
        for (const auto& word2 : dictionary) {
            std::string concatenated = word1 + word2;
            std::string hash = hashCalculator.computeHash(concatenated);
            auto it = hashes.find(hash);
            if (it != hashes.end()) {
                std::cout << "Cracked! ID: " << it->second << ", Password: " << concatenated << std::endl;
            }
        }
    }
}

void PasswordCracker::guessWordsAndDigits(HashHandler& hashCalculator, const std::unordered_map<std::string, std::string>& hashes, const std::vector<std::string>& dictionary) {
    for (const auto& word : dictionary) {
        for (int i = 0; i <= 9999; ++i) { //few digits (1-4 digits)
            std::string guess = word + std::to_string(i); //digits come after word
            std::string hash = hashCalculator.computeHash(guess);
            auto it = hashes.find(hash);
            if (it != hashes.end()) {
                std::cout << "Cracked! ID: " << it->second << ", Password: " << guess << std::endl;
            }
        }
    }
}