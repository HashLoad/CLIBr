#pragma once

#ifndef COMMANDHELP_H
#define COMMANDHELP_H

#include <string>
#include "../clibr.interfaces.h"

namespace clibr
{
    class CommandHelp : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandHelp() override;
    };
}

#endif // COMMANDHELP_H
