#pragma once

#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>

namespace clibr
{
    class Print
    {
    public:
        static void printCreate(const std::string& title, const std::string& text, const std::string& message);
        static void printUpdate(const std::string& title, const std::string& text, const std::string& message);
        static void printVersion(const std::string& message);
        static void printLink(const std::string& message);
        static void printAlert(const std::string& message);
        static void printHelp(const std::string& message);

    private:
        static const char* _reset;
        static const char* _red;
        static const char* _green;
        static const char* _blue;
        static const char* _yellow;
        static const char* _magenta;
        static const char* _cyan;
        static const char* _white;
    };
}

#endif // PRINT_H