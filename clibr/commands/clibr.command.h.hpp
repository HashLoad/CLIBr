#pragma once

#ifndef COMMANDHELP_H
#define COMMANDHELP_H

#include <string>
#include "../clibr.interfaces.hpp"

namespace clibr
{
    class CommandHelp : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName, 
            ICli* cli) override;
        ~CommandHelp() override = default;
    private:
        void _executeInternal();
        void _executeInternalG();
        void _executeInternalN();
    };
}

#endif // COMMANDHELP_H
