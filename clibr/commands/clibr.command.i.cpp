#include <iostream>
#include <string>
#include "clibr.command.i.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

bool clibr::CommandInfra::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::cout << "version";

    return true;
};

clibr::CommandInfra::~CommandInfra() {};
