#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.all.h"
#include "core/clibr.utils.h"
#include "core/clibr.print.h"
#include "core/clibr.command.pair.h"
#include "../clibr.interfaces.h"

bool clibr::CommandAll::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string allPath = dirName;
    std::string sourcePath = dirName;
    bool isHorse = false;

    if (allPath.empty() || allPath == ".")
    {
        allPath = "./src/";
        sourcePath = "./src";
    }

    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }

    if (!std::filesystem::exists(allPath))
    {
        bool isCreate = std::filesystem::create_directories(allPath);
    }
    sourcePath += "/modules/" + fileName;

    // Horse
    if (cli->tags().contains("--horse")) {
        isHorse = cli->tags().at("--horse");
    }

    if (isHorse) {
        _createRouteHandleHorse(sourcePath, fileName, cli);
    }
    else {
        _createRouteHandle(sourcePath, fileName, cli);
    }
    _createModule(sourcePath, fileName, cli);
    _createController(sourcePath + "/controllers", fileName, cli);
    _createService(sourcePath + "/services", fileName, cli);

    return true;
};

clibr::CommandAll::~CommandAll() {};

void clibr::CommandAll::_createModule(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair = cli->commands().at("g").at("m");
    clibr::ICommand* command = commandPair->getCommand();
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createController(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair = cli->commands().at("g").at("c");
    clibr::ICommand* command = commandPair->getCommand();
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createService(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair = cli->commands().at("g").at("s");
    clibr::ICommand* command = commandPair->getCommand();
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createRouteHandleHorse(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair = cli->optionsInternal().at("horse-handler");
    clibr::ICommand* command = commandPair->getCommand();
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createRouteHandle(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair = cli->optionsInternal().at("handler");
    clibr::ICommand* command = commandPair->getCommand();
    bool isSuccess = command->execute(dirName, fileName, cli);
}
