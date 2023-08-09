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
    private:
        void _createProject(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createAppModule(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createModule(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createController(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createService(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createProjectHorse(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createRouteHandleHorse(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createRouteHandle(const std::string& dirName, const std::string& fileName, ICli* cli);
        void _createProjectVCL(const std::string& dirName, const std::string& fileName, ICli* cli);
    };
}

#endif // COMMANDPROJECT_H
