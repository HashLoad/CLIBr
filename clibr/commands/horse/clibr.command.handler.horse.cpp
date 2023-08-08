#include <iostream>
#include <string>
#include "clibr.command.handler.horse.h"
#include "../core/clibr.utils.h"
#include "../core/clibr.print.h"
#include "../../clibr.interfaces.h"

bool clibr::CommandRouteHandlerHorse::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::cout << "version";

    return true;
};

clibr::CommandRouteHandlerHorse::~CommandRouteHandlerHorse(){};
