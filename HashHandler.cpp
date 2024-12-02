#include "HashHandler.h"

std::string HashHandler::computeHash(const std::string& input) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);

    std::ostringstream oss;
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    return oss.str();
}