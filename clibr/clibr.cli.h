#pragma once

#ifndef _CLI_H
#define _CLI_H

#include <map>
#include <list>
#include <string>
#include "clibr.interfaces.h"
#include "core/clibr.command.pair.h"

class Cli : public ICli
{
  private:
    std::map<std::string, CommandPair*> _optionsNew;
    std::map<std::string, CommandPair*> _optionsInfos;
    std::map<std::string, CommandPair*> _optionsHelp;
    std::map<std::string, CommandPair*> _optionsGenerate;
    std::map<std::string, CommandPair*> _optionsInternal;
    std::map<std::string, std::map<std::string, CommandPair*>&> _commands;
    std::map<std::string, bool> _tags;
    std::list<std::string> _updates;
    std::string _pathCLI;
    std::string _commandExecuted;
public:
    Cli(std::string pathCLI);
    ~Cli() override;
    std::string& pathCLI() override;
    std::string& commandExecuted() override;
    std::map<std::string, std::map<std::string, CommandPair*>&>& commands()
        override;
    std::map<std::string, CommandPair*>& optionsInternal() override;
    std::map<std::string, bool>& tags() override;
    std::list<std::string>& updates() override;
    void commandExecuted(const std::string& value) override;
};

#endif // _CLI_H
