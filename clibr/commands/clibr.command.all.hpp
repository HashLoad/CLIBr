#pragma once

#ifndef COMMANDALL_H
#define COMMANDALL_H

#include "../clibr.pch.hpp"

namespace clibr
{
    class CommandAll : public ICommand
    {
    public:
        bool execute(const std::string& dirName, const std::string& fileName,
            ICli* cli) override;
        ~CommandAll() override = default;
    private:
        void _createModule(const std::string& dirName, const std::string& fileName, clibr::ICli* cli);
        void _createController(const std::string& dirName, const std::string& fileName, clibr::ICli* cli);
        void _createService(const std::string& dirName, const std::string& fileName, clibr::ICli* cli);
        void _createRouteHandleHorse(const std::string& dirName, const std::string& fileName, clibr::ICli* cli);
        void _createRouteHandle(const std::string& dirName, const std::string& fileName, clibr::ICli* cli);
    };
}

#endif // COMMANDALL_H
