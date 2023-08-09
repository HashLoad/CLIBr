#pragma once

#ifndef COMMANDINFO_H
#define COMMANDINFO_H

#include <string>
#include "../clibr.interfaces.hpp"

namespace clibr
{
    class CommandInfo : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandInfo() override;
    };
}

#endif // COMMANDINFO_H
