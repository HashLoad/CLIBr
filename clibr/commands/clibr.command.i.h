#pragma once

#ifndef COMMANDINFRA_H
#define COMMANDINFRA_H

#include <string>
#include "../clibr.interfaces.h"

namespace clibr
{
    class CommandInfra : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandInfra() override;
    };
}

#endif // COMMANDINFRA_H