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
        bool execute([[maybe_unused]] const std::string& dirName, 
            [[maybe_unused]] const std::string& fileName, [[maybe_unused]] ICli* cli) override;
        ~CommandTemplates() override = default;
    };
}

#endif // COMMANDTEMP_H
