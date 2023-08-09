#pragma once

#ifndef COMMANDVERSION_H
#define COMMANDVERSION_H

#include <string>
#include "../clibr.interfaces.hpp"

namespace clibr
{
    class CommandVersion : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandVersion() override;
    };
}

#endif // COMMANDVERSION_H
