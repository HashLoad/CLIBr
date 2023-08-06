#include <iostream>
#include "core/clibr.command.pair.h"
#include "commands/clibr.command.v.h"
#include "clibr.cli.h"

Cli::Cli(std::string pathCLI)
{
    this->_pathCLI = pathCLI;
    this->_optionsInfos = { { "version", new CommandPair(new CommandVersion()) },
                            { "v", new CommandPair(new CommandVersion()) } };
    
    this->_commands = { {"version", this->_optionsInfos},
                        {"v", this->_optionsInfos} };
}

Cli::~Cli() {
    for (auto& command : _optionsInfos)
    {
        delete command.second;
    }
    _optionsInfos.clear();

    for (auto& command : _optionsNew)
    {
        delete command.second;
    }
    _optionsNew.clear();
}

std::string& Cli::pathCLI()
{
    return this->_pathCLI;
}

std::string& Cli::commandExecuted()
{
    return this->_commandExecuted;
}

void Cli::commandExecuted(const std::string& value)
{
    this->_commandExecuted = value;
}

std::map<std::string, std::map<std::string, CommandPair*>&>& Cli::commands()
{
    return this->_commands;
}

std::map<std::string, CommandPair*>& Cli::optionsInternal()
{
    return this->_optionsInternal;
}

std::map<std::string, bool>& Cli::tags()
{
    return this->_tags;
}

std::list<std::string>& Cli::updates()
{
    return this->_updates;
}
