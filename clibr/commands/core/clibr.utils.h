#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <list>

namespace clibr
{
    class Utils
    {
    public:
        static std::string getSizeFile(const std::string& path);
        static std::string toLowerCase(const std::string& input);
        static std::string regexReplaceAll(const std::string& input, const std::string& pattern, const std::string& replacement);
        static std::string replaceString(const std::string& original, const std::string& pattern, const std::string& replacement);
        static std::string readFromFile(const std::string& filePath);
        static std::string join(const std::vector<std::string>& strings, char delimiter);
        static std::string version();
        static bool writeToFile(const std::string& filePath, const std::string& content);
    };
}

#endif // UTILS_H