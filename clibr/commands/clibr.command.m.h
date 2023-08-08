#pragma once

#ifndef COMMANDMODULE_H
#define COMMANDMODULE_H

#include <string>
#include "../clibr.interfaces.h"

namespace clibr
{
    class CommandModule : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandModule() override;
    private:
      bool _argGuardExist(ICli* cli);
      std::string _generateGuardBody(std::string& camelCaseName, ICli* cli);
      std::string _generateGuardHeader(std::string& camelCaseName, ICli* cli);
    };
}

#endif // COMMANDMODULE_H
