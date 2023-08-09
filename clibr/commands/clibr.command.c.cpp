#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.c.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

bool clibr::CommandController::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }
    std::string unitName = clibr::Utils::toLowerCase(fileName);
    std::string camelCaseName = std::string(1, std::toupper(fileName[0])) + fileName.substr(1);
    std::string className = "T" + camelCaseName + "Controller";
    std::string sourcePath = dirName;

    if (sourcePath.empty() || sourcePath == ".")
    {
        sourcePath = "./src/modules/" + fileName + "/controllers/";
    }

    if (!std::filesystem::exists(sourcePath))
    {
        std::filesystem::create_directories(sourcePath);
    }

    std::string templateFilePath = cli->pathTemp() + "/controller.pas";
    std::string templateFileName = sourcePath + "/" + unitName + ".controller.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{unitName}", unitName);

    modifiedContent = clibr::Utils::replaceString(modifiedContent, "{controllerName}", className);
    modifiedContent = clibr::Utils::replaceString(modifiedContent, "{className}", camelCaseName);

    bool success = clibr::Utils::writeToFile(templateFileName, modifiedContent);
    if (success)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
        // List Update DPR
        std::string update;
        cli->setUpdate(update.append("  ")
            .append(unitName)
            .append(".controller in \'src\\modules\\")
            .append(fileName)
            .append("\\")
            .append(unitName)
            .append(".controller.pas\',"));
    }
    return success;
};

clibr::CommandController::~CommandController() {};
