#pragma once

#ifndef COMMANDHELP_H
#define COMMANDHELP_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandHelp : public ICommand
    {
    public:
        bool execute([[maybe_unused]] const std::string& dirName, 
            [[maybe_unused]] const std::string& fileName, [[maybe_unused]] ICli* cli) override;
        ~CommandHelp() override = default;
    private:
        void _executeInternal();
        void _executeInternalG();
        void _executeInternalN();
    };
}

#endif // COMMANDHELP_H
