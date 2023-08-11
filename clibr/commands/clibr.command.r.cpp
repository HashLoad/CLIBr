#include <iostream>
#include <string>
#include "clibr.command.r.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandRepository::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        std::cout << "version";

        return true;
    };
}