#pragma once

#ifndef COMMANDVERSION_H
#define COMMANDVERSION_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandVersion : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandVersion() override = default;
    };
}

#endif // COMMANDVERSION_H
