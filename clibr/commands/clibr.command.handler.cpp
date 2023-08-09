#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.handler.h"
#include "core/clibr.utils.h"
#include "core/clibr.print.h"
#include "../clibr.interfaces.h"

bool clibr::CommandRouteHandler::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName = clibr::Utils::toLowerCase(fileName);
    std::string camelCaseName = std::string(1, std::toupper(fileName[0])) + fileName.substr(1);
    std::string className = "T" + camelCaseName + "RouteHandler";
    std::string sourcePath = dirName;

    if (sourcePath.empty() || sourcePath == ".")
    {
        sourcePath = "./src/modules/" + fileName;
    }

    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }

    if (!std::filesystem::exists(sourcePath))
    {
        std::filesystem::create_directories(sourcePath);
    }

    std::string templateFilePath = cli->pathTemp() + "/handler.pas";
    std::string templateFileName = sourcePath + "/" + unitName + ".route.handler.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{unitName}", unitName);

    modifiedContent = clibr::Utils::replaceString(modifiedContent, "{handlerName}", className);
    modifiedContent = clibr::Utils::replaceString(modifiedContent, "{className}", camelCaseName);

    bool success = clibr::Utils::writeToFile(templateFileName, modifiedContent);
    if (success)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
        // List Update DPR
        std::string update;
        cli->setUpdate(update.append("  ")
            .append(unitName)
            .append(".route.handler in \'src\\modules\\")
            .append(fileName)
            .append("\\")
            .append(unitName)
            .append(".route.handler.pas\',"));
    }
    return success;
};

clibr::CommandRouteHandler::~CommandRouteHandler() {};
