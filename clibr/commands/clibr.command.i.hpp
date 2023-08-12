#pragma once

#ifndef COMMANDINFRA_H
#define COMMANDINFRA_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandInfra : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandInfra() override = default;
    };
}

#endif // COMMANDINFRA_H
