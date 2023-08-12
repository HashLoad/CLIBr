#pragma once

#ifndef COMMANDROUTEHANDLE_H
#define COMMANDROUTEHANDLE_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandRouteHandler : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandRouteHandler() override = default;
    };
}

#endif // COMMANDROUTEHANDLE_H
