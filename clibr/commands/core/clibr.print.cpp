#include <iostream>
#include <string>
#include "clibr.print.h"

// Definição dos membros estáticos
const char* clibr::Print::_reset = "\u001b" "[0m";
const char* clibr::Print::_red = "\u001b" "[31m";
const char* clibr::Print::_green = "\u001b" "[32m";
const char* clibr::Print::_blue = "\u001b" "[34m";
const char* clibr::Print::_yellow = "\u001b" "[33m";
const char* clibr::Print::_magenta = "\u001b" "[35m";
const char* clibr::Print::_cyan = "\u001b" "[36m";
const char* clibr::Print::_white = "\u001b" "[37m";

void clibr::Print::printCreate(const std::string& title, const std::string& text, const std::string& message)
{
    std::cout << _green << title << " " << text << " " << message << _reset << std::endl;
};

void clibr::Print::printUpdate(const std::string& title, const std::string& text, const std::string& message)
{
    std::cout << _cyan << title << " " + text << " " << message << _reset << std::endl;
};

void clibr::Print::printVersion(const std::string& message)
{
    std::cout << _magenta << message << _reset << std::endl;
};

void clibr::Print::printLink(const std::string& message)
{
    std::cout << _blue << message << _reset << std::endl;
};

void clibr::Print::printAlert(const std::string& message)
{
    std::cout << _red << message << _reset << std::endl;
};

void clibr::Print::printHelp(const std::string& message)
{
    std::cout << _yellow << message << _reset << std::endl;
};