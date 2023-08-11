#include <iostream>
#include <string>
#include "clibr.command.v.hpp"
#include "core/clibr.print.hpp"
#include "core/clibr.utils.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandVersion::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        std::string version{ "Version: " + Utils::version() };
        Print::printVersion(version);
        return true;
    };

    CommandVersion::~CommandVersion() {};
}