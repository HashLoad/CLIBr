#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.dpr.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "core/clibr.command.pair.hpp"
#include "console/clibr.command.dpr.console.hpp"
#include "vcl/clibr.command.dfm.vcl.hpp"
#include "vcl/clibr.command.pas.vcl.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandGenerateProject::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        if (fileName.empty())
        {
            Print::printAlert("Invalid parameters!");
            return false;
        }
        std::string projectPath{ dirName };
        std::string sourcePath{ dirName };

        if (!std::filesystem::exists(projectPath))
        {
            if (!std::filesystem::create_directories(projectPath))
            {
                return false;
            }
        }
        sourcePath += "/src/modules/ping";

        const MapTags& tags{ cli->tags() };
        // VCL
        bool isVCL{ cli->tags().at("--vcl") };

        // Horse
        bool isHorse{ cli->tags().at("--horse") };

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

    CommandGenerateProject::~CommandGenerateProject() {};

    void CommandGenerateProject::_createProject(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandGenerateProjectConsole projectConsole;
        projectConsole.execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createAppModule(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        _createModule(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createModule(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandPair* commandPair{ cli->commands().at("g").at("m") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };
        command->execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createController(const std::string& dirName,
        const std::string& fileName, ICli* cli) {
        CommandPair* commandPair{ cli->commands().at("g").at("c") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };
        command->execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createService(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandPair* commandPair{ cli->commands().at("g").at("s") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };
        command->execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createProjectHorse(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandPair* commandPair{ cli->optionsInternal().at("horse-app") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };
        command->execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createRouteHandleHorse(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandPair* commandPair{ cli->optionsInternal().at("horse-handler") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };
        command->execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createRouteHandle(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandPair* commandPair{ cli->optionsInternal().at("handler") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };
        command->execute(dirName, fileName, cli);
    }

    void CommandGenerateProject::_createProjectVCL(const std::string& dirName,
        const std::string& fileName, ICli* cli)
    {
        CommandGenerateFormVCL formVCL;
        CommandGenerateUnitVCL unitVCL;
        CommandPair* commandPair{ cli->optionsInternal().at("vcl-app") };
        std::shared_ptr<ICommand> command{ commandPair->getCommand() };

        command->execute(dirName, fileName, cli);
        formVCL.execute(dirName, fileName, cli);
        unitVCL.execute(dirName, fileName, cli);
    }
}