#include <iostream>
#include <string>
#include "clibr.command.dpr.console.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandGenerateProjectConsole::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        std::string unitName{ Utils::toLowerCase(fileName) };
        std::string camelCaseName{ std::string(1, std::toupper(fileName[0])) + fileName.substr(1) };
        std::string programName{ Utils::regexReplaceAll(camelCaseName, "-", "_") };
        std::string templateFilePath{ cli->pathTemp() + "/console.project.pas" };
        std::string templateFileName{ dirName + "/" + unitName + ".dpr" };
        std::string templateContent{ Utils::readFromFile(templateFilePath) };
        std::string modifiedContent{ Utils::replaceString(templateContent, "{programName}", programName) };

        bool isSuccess{ Utils::writeToFile(templateFileName, modifiedContent) };
        if (isSuccess)
        {
            Print::printCreate("CREATE", templateFileName, Utils::getSizeFile(templateFileName));
        }
        return isSuccess;
    };
}