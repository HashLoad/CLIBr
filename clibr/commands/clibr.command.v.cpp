#include <iostream>
#include <string>
#include "clibr.command.v.hpp"
#include "core/clibr.print.hpp"
#include "core/clibr.utils.hpp"
#include "../clibr.interfaces.hpp"

bool clibr::CommandVersion::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string version = "Version: " + clibr::Utils::version();
    clibr::Print::printVersion(version);
    return true;
};

clibr::CommandVersion::~CommandVersion() {};
