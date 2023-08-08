#include <iostream>
#include <string>
#include "clibr.command.v.h"
#include "core/clibr.print.h"
#include "core/clibr.utils.h"
#include "../clibr.interfaces.h"

bool clibr::CommandVersion::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string version = "Version: " + clibr::Utils::version();
    clibr::Print::printVersion(version);
    return true;
};

clibr::CommandVersion::~CommandVersion() {};
