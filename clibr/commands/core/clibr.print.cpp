#include <iostream>
#include <string>
#include "clibr.print.hpp"

namespace clibr
{
    // Defini��o dos membros est�ticos
    const char* Print::_reset{ "\u001b" "[0m" };
    const char* Print::_red{ "\u001b" "[31m" };
    const char* Print::_green{ "\u001b" "[32m" };
    const char* Print::_blue{ "\u001b" "[34m" };
    const char* Print::_yellow{ "\u001b" "[33m" };
    const char* Print::_magenta{ "\u001b" "[35m" };
    const char* Print::_cyan{ "\u001b" "[36m" };
    const char* Print::_white{ "\u001b" "[37m" };

    void Print::printCreate(const std::string& title, const std::string& text, const std::string& message)
    {
        std::cout << _green << title << " " << text << " " << message << _reset << '\n';
    };

    void Print::printUpdate(const std::string& title, const std::string& text, const std::string& message)
    {
        std::cout << _cyan << title << " " + text << " " << message << _reset << '\n';
    };

    void Print::printVersion(const std::string& message)
    {
        std::cout << _magenta << message << _reset << '\n';
    };

    void Print::printLink(const std::string& message)
    {
        std::cout << _blue << message << _reset << '\n';
    };

    void Print::printAlert(const std::string& message)
    {
        std::cout << _red << message << _reset << '\n';
    };

    void Print::printHelp(const std::string& message)
    {
        std::cout << _yellow << message << _reset << '\n';
    };
}