#include <iostream>
#include <string>
#include "clibr.command.dpr.h"
#include "../clibr.interfaces.h"

bool CommandUpdateDpr::execute(
    const std::string& dirName, const std::string& fileName, const ICli* cli)
{
    std::cout << "version";

    return true;
};

CommandUpdateDpr::~CommandUpdateDpr() {};

