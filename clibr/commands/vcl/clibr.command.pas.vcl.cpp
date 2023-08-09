#include <iostream>
#include <string>
#include "clibr.command.pas.vcl.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.interfaces.hpp"

bool clibr::CommandGenerateUnitVCL::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }
    std::string unitName{ clibr::Utils::toLowerCase(fileName) };
    std::string templateFilePath{ cli->pathTemp() + "/vcl.project.unit.pas" };
    std::string templateFileName{ dirName + "/u" + unitName + ".pas" };
    std::string templateContent{ clibr::Utils::readFromFile(templateFilePath) };
    std::string modifiedContent{ clibr::Utils::replaceString(templateContent, "{unitName}", unitName) };

    bool isSuccess{ clibr::Utils::writeToFile(templateFileName, modifiedContent) };
    if (isSuccess)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
    }
    return isSuccess;
};

clibr::CommandGenerateUnitVCL::~CommandGenerateUnitVCL(){};
