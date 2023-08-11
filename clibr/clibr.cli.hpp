#pragma once

#ifndef CLI_H
#define CLI_H

#include <map>
#include <list>
#include <string>
#include "clibr.interfaces.hpp"
#include "commands/core/clibr.command.pair.hpp"
#include "commands/core/clibr.typedefs.hpp"

namespace clibr
{
    class Cli : public ICli
    {
    private:
        const std::string& _pathTemp;
        std::string _commandExecuted;
        MapOptions _optionsNew;
        MapOptions _optionsInfos;
        MapOptions _optionsHelp;
        MapOptions _optionsGenerate;
        MapOptions _optionsInternal;
        MapCommands _commands;
        MapTags _tags;
        ListUpdates _updates;
    public:
        Cli(const std::string& pathTemp);
        ~Cli() override;
        const std::string& pathTemp() const override;
        const std::string& commandExecuted() const override;
        const MapCommands& commands() const override;
        const MapOptions& optionsInternal() const override;
        const MapTags& tags() const override;
        const ListUpdates& updates() const override;
        void commandExecuted(const std::string& value) override;
        void setTagValue(const std::string& name, const bool value) override;
        void setUpdate(const std::string& value) override;
    };
}

#endif // CLI_H
