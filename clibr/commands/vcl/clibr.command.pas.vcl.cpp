#include <iostream>
#include <string>
#include "clibr.command.pas.vcl.h"
#include "../core/clibr.utils.h"
#include "../core/clibr.print.h"
#include "../../clibr.interfaces.h"

bool clibr::CommandGenerateUnitVCL::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::cout << "version";

    return true;
};

clibr::CommandGenerateUnitVCL::~CommandGenerateUnitVCL(){};
