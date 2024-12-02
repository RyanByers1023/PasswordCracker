#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include "HashHandler.h"

class PasswordCracker {
public:
	void crackPasswords(const std::unordered_map<std::string, std::string>& hashes, const std::vector<std::string>& dictionary);

private:
	void guessDigitsOnly(HashHandler& hashCalculator, const std::unordered_map<std::string, std::string>& hashes);

	void guessWordsOnly(HashHandler& hashCalculator, const std::unordered_map<std::string, std::string>& hashes, const std::vector<std::string>& dictionary);

	void guessWordsAndDigits(HashHandler& hashCalculator, const std::unordered_map<std::string, std::string>& hashes, const std::vector<std::string>& dictionary);
};