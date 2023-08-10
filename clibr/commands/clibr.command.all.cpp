#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.all.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "core/clibr.command.pair.hpp"
#include "../clibr.interfaces.hpp"

bool clibr::CommandAll::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }
    std::string allPath{ dirName };
    std::string sourcePath{ dirName };

    if (allPath.empty() || allPath == ".")
    {
        allPath = "./src/";
        sourcePath = "./src";
    }

    if (!std::filesystem::exists(allPath))
    {
        bool isCreate{ std::filesystem::create_directories(allPath) };
    }
    sourcePath += "/modules/" + fileName;

    // Horse
    bool isHorse{ cli->tags().at("--horse") };

    isHorse ? _createRouteHandleHorse(sourcePath, fileName, cli) : 
              _createRouteHandle(sourcePath, fileName, cli);

    _createModule(sourcePath, fileName, cli);
    _createController(sourcePath + "/controllers", fileName, cli);
    _createService(sourcePath + "/services", fileName, cli);

    return true;
};

clibr::CommandAll::~CommandAll() {};

void clibr::CommandAll::_createModule(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair{ cli->commands().at("g").at("m") };
    std::shared_ptr<ICommand> command{ commandPair->getCommand() };
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createController(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair{ cli->commands().at("g").at("c") };
    std::shared_ptr<ICommand> command{ commandPair->getCommand() };
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createService(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair{ cli->commands().at("g").at("s") };
    std::shared_ptr<ICommand> command{ commandPair->getCommand() };
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createRouteHandleHorse(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair{ cli->optionsInternal().at("horse-handler") };
    std::shared_ptr<ICommand> command{ commandPair->getCommand() };
    bool isSuccess = command->execute(dirName, fileName, cli);
}

void clibr::CommandAll::_createRouteHandle(const std::string& dirName, 
    const std::string& fileName, clibr::ICli* cli) 
{
    clibr::CommandPair* commandPair{ cli->optionsInternal().at("handler") };
    std::shared_ptr<ICommand> command{ commandPair->getCommand() };
    bool isSuccess = command->execute(dirName, fileName, cli);
}
