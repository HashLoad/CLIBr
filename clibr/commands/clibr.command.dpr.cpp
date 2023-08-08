#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.dpr.h"
#include "core/clibr.utils.h"
#include "core/clibr.print.h"
#include "core/clibr.command.pair.h"
#include "console/clibr.command.dpr.console.h"
#include "vcl/clibr.command.dfm.vcl.h"
#include "vcl/clibr.command.pas.vcl.h"
#include "../clibr.interfaces.h"

bool clibr::CommandGenerateProject::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string projectPath = dirName;
    std::string sourcePath = dirName;
    bool isHorse = false;
    bool isVCL = false;

    if (sourcePath.empty())
    {
        projectPath = "./";
        sourcePath = ".";
    }

    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }

    if (!std::filesystem::exists(projectPath))
    {
        std::filesystem::create_directories(projectPath);
    }
    sourcePath += "/src/modules/ping";
    // VCL
    if (cli->tags().contains("--vcl")) {
        isVCL = cli->tags().at("--vcl");
    }
 
    // Horse
    if (cli->tags().contains("--horse")) {
        isHorse = cli->tags().at("--horse");
    }
 
    if (isHorse) {
        _createProjectHorse(projectPath, fileName, cli);
        _createAppModule(projectPath + "/src", "app", cli);
        _createRouteHandleHorse(sourcePath, "ping", cli);
    }
    else if (isVCL) {
        _createProjectVCL(projectPath, fileName, cli);
        _createAppModule(projectPath + "/src", "app", cli);
        _createRouteHandle(sourcePath, "ping", cli);
    }
    else {
        _createProject(projectPath, fileName, cli);
        _createAppModule(projectPath + "/src", "app", cli);
        _createRouteHandle(sourcePath, "ping", cli);
    }
    _createModule(sourcePath, "ping", cli);
    _createController(sourcePath + "/controllers", "ping", cli);
    _createService(sourcePath + "/services", "ping", cli);

    return true;
};

clibr::CommandGenerateProject::~CommandGenerateProject() {};

void clibr::CommandGenerateProject::_createProject(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandGenerateProjectConsole projectConsole;
    projectConsole.execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createAppModule(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandPair* commandPair = cli->commands().at("g").at("m");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createModule(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandPair* commandPair = cli->commands().at("g").at("m");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createController(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) {
    clibr::CommandPair* commandPair = cli->commands().at("g").at("c");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createService(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandPair* commandPair = cli->commands().at("g").at("s");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createProjectHorse(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandPair* commandPair = cli->optionsInternal().at("horse-app");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createRouteHandleHorse(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandPair* commandPair = cli->optionsInternal().at("horse-handler");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createRouteHandle(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandPair* commandPair = cli->optionsInternal().at("handler");
    clibr::ICommand* command = commandPair->getCommand();
    command->execute(dirName, fileName, cli);
}

void clibr::CommandGenerateProject::_createProjectVCL(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli)
{
    clibr::CommandGenerateFormVCL formVCL;
    clibr::CommandGenerateUnitVCL unitVCL;
    clibr::CommandPair* commandPair = cli->optionsInternal().at("vcl-app");
    clibr::ICommand* command = commandPair->getCommand();

    command->execute(dirName, fileName, cli);
    formVCL.execute(dirName, fileName, cli);
    unitVCL.execute(dirName, fileName, cli);
}

