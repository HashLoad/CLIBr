#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <regex>
#include "clibr.utils.hpp"

std::string clibr::Utils::getSizeFile(const std::string& path)
{
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        return "Error while opening the file";
    }

    std::streampos size{ file.tellg() };
    file.close();

    if (size < 0)
    {
        return "Error while getting the file size";
    }

    return "(" + std::to_string(size) + " bytes)";
};

std::string clibr::Utils::toLowerCase(const std::string& input)
{
    std::string result;
    for (char c : input) {
        result += std::tolower(c);
    }
    return result;
}

std::string clibr::Utils::regexReplaceAll(const std::string& input,
    const std::string& pattern, const std::string& replacement)
{
    std::regex regexPattern(pattern);
    return std::regex_replace(input, regexPattern, replacement);
}

std::string clibr::Utils::readFromFile(const std::string& filePath)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error while opening the file: " << filePath << std::endl;
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>());
    inputFile.close();
    return content;
}

bool clibr::Utils::writeToFile(const std::string& filePath, const std::string& content)
{
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) 
    {
        std::cerr << "Error while opening the file for writing: " << filePath << std::endl;
        return false;
    }
    outputFile << content;
    outputFile.close();
    return true;
}

std::string clibr::Utils::replaceString(const std::string& original,
    const std::string& pattern, const std::string& replacement) 
{
    std::string result{ original };
    size_t pos = 0;

    while ((pos = result.find(pattern, pos)) != std::string::npos) 
    {
        result.replace(pos, pattern.length(), replacement);
        pos += replacement.length();
    }
    return result;
}

std::string clibr::Utils::join(const std::vector<std::string>& strings, char delimiter)
{
    std::string result;
    for (const std::string& str : strings) {
        result += str + delimiter;
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

std::string clibr::Utils::version()
{
    return "0.0.1";
}