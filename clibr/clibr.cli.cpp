#include <iostream>
#include "commands/core/clibr.command.pair.hpp"
#include "commands/horse/clibr.command.dpr.horse.hpp"
#include "commands/horse/clibr.command.handler.horse.hpp"
#include "commands/console/clibr.command.dpr.console.hpp"
#include "commands/vcl/clibr.command.dfm.vcl.hpp"
#include "commands/vcl/clibr.command.dpr.vcl.hpp"
#include "commands/vcl/clibr.command.pas.vcl.hpp"
#include "commands/clibr.command.templates.hpp"
#include "commands/clibr.command.handler.hpp"
#include "commands/clibr.command.info.hpp"
#include "commands/clibr.command.pipe.hpp"
#include "commands/clibr.command.dpr.hpp"
#include "commands/clibr.command.all.hpp"
#include "commands/clibr.command.h.hpp"
#include "commands/clibr.command.v.hpp"
#include "commands/clibr.command.m.hpp"
#include "commands/clibr.command.c.hpp"
#include "commands/clibr.command.i.hpp"
#include "commands/clibr.command.s.hpp"
#include "commands/clibr.command.r.hpp"
#include "clibr.cli.hpp"


namespace clibr
{
    Cli::Cli(const std::string& pathTemp) : _pathTemp(pathTemp)
    {
        this->_optionsInfos =
        {
            { "version", new CommandPair(std::make_shared<CommandVersion>()) },
            { "v", new CommandPair(std::make_shared<CommandVersion>()) },
            { "info", new CommandPair(std::make_shared<CommandInfo>()) },
            { "i", new CommandPair(std::make_shared<CommandInfo>()) },
            { "templates", new CommandPair(std::make_shared<CommandTemplates>()) },
            { "t", new CommandPair(std::make_shared<CommandTemplates>()) },
        };

        this->_optionsHelp =
        {
            { "--help", new CommandPair(std::make_shared<CommandHelp>()) },
            { "-h", new CommandPair(std::make_shared<CommandHelp>()) },
        };

        this->_optionsNew =
        {
            { "application", new CommandPair(std::make_shared<CommandGenerateProject>()) },
            { "app", new CommandPair(std::make_shared<CommandGenerateProject>()) },
            { "new", new CommandPair(std::make_shared<CommandGenerateProject>()) },
            { "--help", new CommandPair(std::make_shared<CommandHelp>()) },
            { "-h", new CommandPair(std::make_shared<CommandHelp>()) },
        };

        this->_optionsGenerate =
        {
            { "module", new CommandPair(std::make_shared<CommandModule>()) },
            { "m", new CommandPair(std::make_shared<CommandModule>()) },
            { "controller", new CommandPair(std::make_shared<CommandController>()) },
            { "c", new CommandPair(std::make_shared<CommandController>()) },
            { "service", new CommandPair(std::make_shared<CommandService>()) },
            { "s", new CommandPair(std::make_shared<CommandService>()) },
            { "repository", new CommandPair(std::make_shared<CommandRepository>()) },
            { "r", new CommandPair(std::make_shared<CommandRepository>()) },
            { "infra", new CommandPair(std::make_shared<CommandInfra>()) },
            { "i", new CommandPair(std::make_shared<CommandInfra>()) },
            { "pipe", new CommandPair(std::make_shared<CommandTransformPipe>()) },
            { "p", new CommandPair(std::make_shared<CommandTransformPipe>()) },
            { "all", new CommandPair(std::make_shared<CommandAll>()) },
            { "--help", new CommandPair(std::make_shared<CommandHelp>()) },
            { "-h", new CommandPair(std::make_shared<CommandHelp>()) },
        };

        this->_optionsInternal =
        {
            { "handler", new CommandPair(std::make_shared<CommandRouteHandler>()) },
            { "horse-app", new CommandPair(std::make_shared<CommandGenerateProjectHorse>()) },
            { "horse-handler", new CommandPair(std::make_shared<CommandRouteHandlerHorse>()) },
            { "vcl-app", new CommandPair(std::make_shared<CommandGenerateProjectVCL>()) },
        };

        this->_commands =
        {
            { "new", _optionsNew },
            { "n", _optionsNew },
            { "generate", _optionsGenerate },
            { "g", _optionsGenerate },
            { "info", _optionsInfos },
            { "i", _optionsInfos },
            { "templates", _optionsInfos },
            { "t", _optionsInfos },
            { "version", _optionsInfos },
            { "v", _optionsInfos },
            { "--help", _optionsHelp },
            { "-h", _optionsHelp },
        };

        this->_tags =
        {
            { "-gu", false },
            { "--guard", false },
            { "--horse", false },
            { "--vcl", false },
        };
    }

    Cli::~Cli()
    {
        for (forPair& command : this->_optionsInfos)
        {
            delete command.second;
        }
        this->_optionsInfos.clear();

        for (forPair& command : this->_optionsHelp)
        {
            delete command.second;
        }
        this->_optionsHelp.clear();

        for (forPair& command : this->_optionsNew)
        {
            delete command.second;
        }
        this->_optionsNew.clear();

        for (forPair& command : this->_optionsGenerate)
        {
            delete command.second;
        }
        this->_optionsGenerate.clear();

        for (forPair& command : this->_optionsInternal)
        {
            delete command.second;
        }
        this->_optionsInternal.clear();

        this->_tags.clear();
        this->_commands.clear();
        this->_updates.clear();
    }

    const std::string& Cli::pathTemp() const
    {
        return this->_pathTemp;
    }

    const std::string& Cli::commandExecuted() const
    {
        return this->_commandExecuted;
    }

    void Cli::commandExecuted(const std::string& value)
    {
        this->_commandExecuted = value;
    }

    const MapCommands& Cli::commands() const
    {
        return this->_commands;
    };

    const MapOptions& Cli::optionsInternal() const
    {
        return this->_optionsInternal;
    }

    const MapTags& Cli::tags() const
    {
        return this->_tags;
    }

    const ListUpdates& Cli::updates() const
    {
        return this->_updates;
    }

    void Cli::setTagValue(const std::string& name, const bool value)
    {
        this->_tags[name] = value;
    }

    void Cli::setUpdate(const std::string& value)
    {
        this->_updates.push_back(value);
    }
}