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

    if (std::filesystem::exists(sourcePath))
    {
        std::filesystem::create_directories(sourcePath);
    }

    std::string templateFilePath = "";
    if (isAppModule)
    {
        templateFilePath = cli->pathCLI() + "/module.app.pas";
    }
    else
    {
        templateFilePath = cli->pathCLI() + "/module.pas";
    }
    std::string templateFileName = sourcePath + "/" + unitName + ".module.dpr";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{moduleName}", className);
    
    modifiedContent = clibr::Utils::replaceString(templateContent, "{unitName}", unitName);
    modifiedContent = clibr::Utils::replaceString(templateContent, "{className}", camelCaseName);

    // Guard exist
    isGuard = _argGuardExist(cli);
    if (isGuard) {
        modifiedContent = clibr::Utils::replaceString(templateContent, "{guardCode}", _generateGuardBody(camelCaseName, cli));
        modifiedContent = clibr::Utils::replaceString(templateContent, "{guardHeader}", _generateGuardHeader(camelCaseName, cli));
    }

    bool success = clibr::Utils::writeToFile(templateFileName, modifiedContent);

    return true;
};

clibr::CommandModule::~CommandModule() {};

bool clibr::CommandModule::_argGuardExist(ICli* cli)
{
    bool result = false;
    if (cli->tags().count("--guard") > 0)
    {
        result = cli->tags().at("--guard");
    }
    else if (cli->tags().count("-gu") > 0)
    {
        result = cli->tags().at("-gu");
    }
    return result;
}

std::string clibr::CommandModule::_generateGuardBody(std::string& camelCaseName, ICli* cli)
{
    std::string templateFilePath = cli->pathCLI() + "/" + "body.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{className}", "T" + camelCaseName);

    return modifiedContent;
}

std::string clibr::CommandModule::_generateGuardHeader(std::string& camelCaseName, ICli* cli)
{
    std::string templateFilePath = cli->pathCLI() + "/" + "header.pas";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{className}", "T" + camelCaseName);

    return modifiedContent;

}
