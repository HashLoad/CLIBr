#include <iostream>
#include <string>
#include "clibr.command.v.h"
#include "../clibr.interfaces.h"

bool CommandVersion::execute(
    const std::string &dirName, const std::string &fileName, const ICli* cli)
{
    std::cout << "version";

    return true;
};

CommandVersion::~CommandVersion() {};

