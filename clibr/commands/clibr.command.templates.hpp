#pragma once

#ifndef COMMANDTEMP_H
#define COMMANDTEMP_H

#include <string>
#include "../clibr.interfaces.hpp"

namespace clibr
{
    class CommandTemplates : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandTemplates() override = default;
    };
}

#endif // COMMANDTEMP_H
