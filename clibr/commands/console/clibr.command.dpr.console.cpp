#include <iostream>
#include <string>
#include "clibr.command.dpr.console.h"
#include "../core/clibr.utils.h"
#include "../core/clibr.print.h"
#include "../../clibr.interfaces.h"

bool clibr::CommandGenerateProjectConsole::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName = clibr::Utils::toLowerCase(fileName);
    std::string camelCaseName = std::string(1, std::toupper(fileName[0])) + fileName.substr(1);
    std::string programName = clibr::Utils::regexReplaceAll(camelCaseName, "-", "_");
    std::string templateFilePath = cli->pathCLI() + "/console.project.pas";
    std::string templateFileName = dirName + "/" + unitName + ".dpr";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{programName}", programName);
    
    bool success = clibr::Utils::writeToFile(templateFileName, modifiedContent);
    
    if (success)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
    }
    return success;
};

clibr::CommandGenerateProjectConsole::~CommandGenerateProjectConsole() {};