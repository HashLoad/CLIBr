#include <iostream>
#include <string>
#include "clibr.command.i.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandInfra::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        std::cout << "version";

        return true;
    };

    CommandInfra::~CommandInfra() {};
}