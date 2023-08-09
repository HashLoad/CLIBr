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
    class Cli : public clibr::ICli
    {
    private:
        const std::string& _pathTemp;
        std::string _commandExecuted;
        clibr::MapOptions _optionsNew;
        clibr::MapOptions _optionsInfos;
        clibr::MapOptions _optionsHelp;
        clibr::MapOptions _optionsGenerate;
        clibr::MapOptions _optionsInternal;
        clibr::MapCommands _commands;
        clibr::MapTags _tags;
        clibr::ListUpdates _updates;
    public:
        Cli(const std::string& pathTemp);
        ~Cli() override;
        const std::string& pathTemp() const override;
        const std::string& commandExecuted() const override;
        const clibr::MapCommands& commands() const override;
        const clibr::MapOptions& optionsInternal() const override;
        const clibr::MapTags& tags() const override;
        const clibr::ListUpdates& updates() const override;
        void commandExecuted(const std::string& value) override;
        void setTagValue(const std::string& name, const bool value) override;
        void setUpdate(const std::string& value) override;
    };
}

#endif // CLI_H
