#pragma once

#ifndef INTERFACES_H
#define INTERFACES_H

#include <map>
#include <list>
#include <string>
#include "commands/core/clibr.typedefs.h"

namespace clibr
{
    class ICli
    {
    public:
        virtual const std::string& pathTemp() const = 0;
        virtual const std::string& commandExecuted() const = 0;
        virtual const clibr::MapCommands& commands() const = 0;
        virtual const clibr::MapOptions& optionsInternal() const = 0;
        virtual clibr::MapTags& tags() = 0;
        virtual clibr::ListUpdates& updates() = 0;
        virtual void commandExecuted(const std::string& value) = 0;
        virtual ~ICli() = 0;
    };

    class ICommand
    {
    public:
        virtual bool execute(const std::string& dirName, const std::string& fileName, ICli* cli) = 0;
        virtual ~ICommand() = 0;
    };
}

#endif // INTERFACES_H
