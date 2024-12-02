#include "FileLoader.h"

std::unordered_map<std::string, std::string> FileLoader::loadHashes(const std::string& filename) {
    std::unordered_map<std::string, std::string> hashMap;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, hash;
        if (iss >> id >> hash)
            hashMap[hash] = id;
    }
    return hashMap;
}

std::vector<std::string> FileLoader::loadDictionary(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    std::string word;
    while (std::getline(file, word)) {
        words.push_back(word);
    }
    return words;
}