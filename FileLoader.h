#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

class FileLoader {
public:
	std::unordered_map<std::string, std::string> loadHashes(const std::string& filename);

	std::vector<std::string> loadDictionary(const std::string& filename);
};