#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/ssl.h>

class HashHandler {
public:
	//utilizes openSSL to efficiently and easily compute hashCalculator.computeHash hashes for a string, input
	std::string computeHash(const std::string& input);
};