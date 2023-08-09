#include <iostream>
#include <string>
#include "clibr.command.dpr.console.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.interfaces.hpp"

bool clibr::CommandGenerateProjectConsole::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName{ clibr::Utils::toLowerCase(fileName) };
    std::string camelCaseName{ std::string(1, std::toupper(fileName[0])) + fileName.substr(1) };
    std::string programName{ clibr::Utils::regexReplaceAll(camelCaseName, "-", "_") };
    std::string templateFilePath{ cli->pathTemp() + "/console.project.pas" };
    std::string templateFileName{ dirName + "/" + unitName + ".dpr" };
    std::string templateContent{ clibr::Utils::readFromFile(templateFilePath) };
    std::string modifiedContent{ clibr::Utils::replaceString(templateContent, "{programName}", programName) };
    
    bool isSuccess{ clibr::Utils::writeToFile(templateFileName, modifiedContent) };
    if (isSuccess)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
    }
    return isSuccess;
};

clibr::CommandGenerateProjectConsole::~CommandGenerateProjectConsole() {};