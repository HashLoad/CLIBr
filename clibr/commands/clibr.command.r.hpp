#pragma once

#ifndef COMMANDREPOSITORY_H
#define COMMANDREPOSITORY_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandRepository : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandRepository() override = default;
    };
}

#endif // COMMANDREPOSITORY_H
