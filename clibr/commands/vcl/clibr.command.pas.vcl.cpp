#include <iostream>
#include <string>
#include "clibr.command.pas.vcl.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandGenerateUnitVCL::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        if (fileName.empty())
        {
            Print::printAlert("Invalid parameters!");
            return false;
        }
        std::string unitName{ Utils::toLowerCase(fileName) };
        std::string templateFilePath{ cli->pathTemp() + "/vcl.project.unit.pas" };
        std::string templateFileName{ dirName + "/u" + unitName + ".pas" };
        std::string templateContent{ Utils::readFromFile(templateFilePath) };
        std::string modifiedContent{ Utils::replaceString(templateContent, "{unitName}", unitName) };

        bool isSuccess{ Utils::writeToFile(templateFileName, modifiedContent) };
        if (isSuccess)
        {
            Print::printCreate("CREATE", templateFileName, Utils::getSizeFile(templateFileName));
        }
        return isSuccess;
    };
}