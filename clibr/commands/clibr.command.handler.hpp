#pragma once

#ifndef COMMANDROUTEHANDLE_H
#define COMMANDROUTEHANDLE_H

#include <string>
#include "../clibr.interfaces.hpp"

namespace clibr
{
    class CommandRouteHandler : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandRouteHandler() override;
    };
}

#endif // COMMANDROUTEHANDLE_H
