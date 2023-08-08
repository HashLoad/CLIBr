#include <iostream>
#include <string>
#include "clibr.command.h.h"
#include "core/clibr.utils.h"
#include "core/clibr.print.h"
#include "../clibr.interfaces.h"

bool clibr::CommandHelp::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    clibr::Print::printVersion("Version 0.0.1");
    return true;
};

clibr::CommandHelp::~CommandHelp() {};