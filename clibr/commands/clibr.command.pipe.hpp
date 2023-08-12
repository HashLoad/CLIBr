#pragma once

#ifndef COMMANDPIPE_H
#define COMMANDPIPE_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandTransformPipe : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandTransformPipe() override = default;
    };
}

#endif // COMMANDPIPE_H
