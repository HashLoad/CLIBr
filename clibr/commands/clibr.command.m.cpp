#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.m.h"
#include "core/clibr.utils.h"
#include "core/clibr.print.h"
#include "../clibr.interfaces.h"

bool clibr::CommandModule::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName = clibr::Utils::toLowerCase(fileName);
    std::string camelCaseName = std::string(1, std::toupper(fileName[0])) + fileName.substr(1);
    std::string className = "T" + camelCaseName + "Module";
    std::string sourcePath = dirName;
    bool isAppModule = (unitName == "app");
    bool isGuard = false;

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

    std::string templateFilePath = "";
    if (isAppModule)
    {
        templateFilePath = cli->pathTemp() + "/module.app.pas";
    }
    else
    {
        templateFilePath = cli->pathTemp() + "/module.pas";
    }
    std::string templateFileName = sourcePath + "/" + unitName + ".module.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{moduleName}", className);

    modifiedContent = clibr::Utils::replaceString(modifiedContent, "{unitName}", unitName);
    modifiedContent = clibr::Utils::replaceString(modifiedContent, "{className}", camelCaseName);

    // Guard exist
    isGuard = _argGuardExist(cli);
    if (isGuard) {
        modifiedContent = clibr::Utils::replaceString(modifiedContent, "{guardCode}",
            _generateGuardBody(camelCaseName, cli));
        modifiedContent = clibr::Utils::replaceString(modifiedContent, "{guardHeader}",
            _generateGuardHeader(camelCaseName, cli));
    }

    bool success = clibr::Utils::writeToFile(templateFileName, modifiedContent);
    if (success)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
        // List Update DPR
        std::string update;
        cli->updates().push_back(update.append("  ")
            .append(unitName)
            .append(".module in \'src\\modules\\")
            .append(fileName)
            .append("\\")
            .append(unitName)
            .append(".module.pas\',")
            .append(","));
    }
    return success;
};

clibr::CommandModule::~CommandModule() {};

bool clibr::CommandModule::_argGuardExist(ICli* cli)
{
    bool result;
    if (cli->tags().contains("--guard"))
    {
        result = cli->tags().at("--guard");
    }
    else if (cli->tags().contains("-gu"))
    {
        result = cli->tags().at("-gu");
    }
    else
    {
        result = false;
    }
    return result;
}

std::string clibr::CommandModule::_generateGuardBody(std::string& camelCaseName, ICli* cli)
{
    std::string templateFilePath = cli->pathTemp() + "/" + "body.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{className}", "T" + camelCaseName);

    return modifiedContent;
}

std::string clibr::CommandModule::_generateGuardHeader(std::string& camelCaseName, ICli* cli)
{
    std::string templateFilePath = cli->pathTemp() + "/" + "header.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{className}", "T" + camelCaseName);

    return modifiedContent;

}
