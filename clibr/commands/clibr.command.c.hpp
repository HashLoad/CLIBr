#pragma once

#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandController : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandController() override = default;
    };
}

#endif // COMMANDCONTROLLER_H
