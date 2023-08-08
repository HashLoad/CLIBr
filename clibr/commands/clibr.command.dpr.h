#pragma once

#ifndef COMMANDPROJECT_H
#define COMMANDPROJECT_H

#include <string>
#include "../clibr.interfaces.h"

namespace clibr
{
    class CommandGenerateProject : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandGenerateProject() override;
    };
}

#endif // COMMANDPROJECT_H
