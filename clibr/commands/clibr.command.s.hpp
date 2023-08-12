#pragma once

#ifndef COMMANDSERVICE_H
#define COMMANDSERVICE_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandService : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandService() override = default;
    };
}

#endif // COMMANDSERVICE_H
