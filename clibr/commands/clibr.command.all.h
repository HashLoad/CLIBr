#pragma once

#ifndef COMMANDALL_H
#define COMMANDALL_H

#include <string>
#include "../clibr.interfaces.h"

namespace clibr
{
    class CommandAll : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandAll() override;
    };
}

#endif // COMMANDALL_H
