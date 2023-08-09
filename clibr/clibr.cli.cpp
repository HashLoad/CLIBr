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

clibr::Cli::Cli(const std::string& pathTemp) : _pathTemp(pathTemp)
{
    this->_optionsInfos = 
    { 
        { "version", new clibr::CommandPair(new clibr::CommandVersion()) },
        { "v", new clibr::CommandPair(new clibr::CommandVersion()) },
        { "info", new clibr::CommandPair(new clibr::CommandInfo()) },
        { "i", new clibr::CommandPair(new clibr::CommandInfo()) },
        { "templates", new clibr::CommandPair(new clibr::CommandTemplates()) },
        { "t", new clibr::CommandPair(new clibr::CommandTemplates()) },
    };

    this->_optionsHelp = 
    {
        { "--help", new clibr::CommandPair(new clibr::CommandHelp()) },
        { "-h", new clibr::CommandPair(new clibr::CommandHelp()) },
    };

    this->_optionsNew = 
    {
        { "application", new clibr::CommandPair(new clibr::CommandGenerateProject()) },
        { "app", new clibr::CommandPair(new clibr::CommandGenerateProject()) },
        { "new", new clibr::CommandPair(new clibr::CommandGenerateProject()) },
        { "--help", new clibr::CommandPair(new clibr::CommandHelp()) },
        { "-h", new clibr::CommandPair(new clibr::CommandHelp()) },
    };

    this->_optionsGenerate = 
    {
        { "module", new clibr::CommandPair(new clibr::CommandModule()) },
        { "m", new clibr::CommandPair(new clibr::CommandModule()) },
        { "controller", new clibr::CommandPair(new clibr::CommandController()) },
        { "c", new clibr::CommandPair(new clibr::CommandController()) },
        { "service", new clibr::CommandPair(new clibr::CommandService()) },
        { "s", new clibr::CommandPair(new clibr::CommandService()) },
        { "repository", new clibr::CommandPair(new clibr::CommandRepository()) },
        { "r", new clibr::CommandPair(new clibr::CommandRepository()) },
        { "infra", new clibr::CommandPair(new clibr::CommandInfra()) },
        { "i", new clibr::CommandPair(new clibr::CommandInfra()) },
        { "pipe", new clibr::CommandPair(new clibr::CommandTransformPipe()) },
        { "p", new clibr::CommandPair(new clibr::CommandTransformPipe()) },
        { "all", new clibr::CommandPair(new clibr::CommandAll()) },
        { "--help", new clibr::CommandPair(new clibr::CommandHelp()) },
        { "-h", new clibr::CommandPair(new clibr::CommandHelp()) },
    };

    this->_optionsInternal =
    {
        { "handler", new clibr::CommandPair(new clibr::CommandRouteHandler()) },
        { "horse-app", new clibr::CommandPair(new clibr::CommandGenerateProjectHorse()) },
        { "horse-handler", new clibr::CommandPair(new clibr::CommandRouteHandlerHorse()) },
        { "vcl-app", new clibr::CommandPair(new clibr::CommandGenerateProjectVCL()) },
    };

    this->_tags = 
    {
        { "-gu", false },
        { "--guard", false },
        { "--horse", false },
        { "--vcl", false },
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
}

clibr::Cli::~Cli()
{
    for (clibr::forPair& command : this->_optionsInfos)
    {
        delete command.second;
    }
    this->_optionsInfos.clear();

    for (clibr::forPair& command : this->_optionsHelp)
    {
        delete command.second;
    }
    this->_optionsHelp.clear();

    for (clibr::forPair& command : this->_optionsNew)
    {
        delete command.second;
    }
    this->_optionsNew.clear();

    for (clibr::forPair& command : this->_optionsGenerate)
    {
        delete command.second;
    }
    this->_optionsGenerate.clear();

    for (clibr::forPair& command : this->_optionsInternal)
    {
        delete command.second;
    }
    this->_optionsInternal.clear();

    this->_tags.clear();
    this->_commands.clear();
    this->_updates.clear();
}

const std::string& clibr::Cli::pathTemp() const
{
    return this->_pathTemp;
}

const std::string& clibr::Cli::commandExecuted() const
{
    return this->_commandExecuted;
}

void clibr::Cli::commandExecuted(const std::string& value)
{
    this->_commandExecuted = value;
}

const clibr::MapCommands& clibr::Cli::commands() const
{
    return this->_commands;
};

const clibr::MapOptions& clibr::Cli::optionsInternal() const
{
    return this->_optionsInternal;
}

const clibr::MapTags& clibr::Cli::tags() const 
{
    return this->_tags;
}

const clibr::ListUpdates& clibr::Cli::updates() const 
{
    return this->_updates;
}

void clibr::Cli::setTagValue(const std::string& name, const bool value)
{
    this->_tags[name] = value;
}

void clibr::Cli::setUpdate(const std::string& value)
{
    this->_updates.push_back(value);
}