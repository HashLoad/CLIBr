#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.s.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandService::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        if (fileName.empty())
        {
            Print::printAlert("Invalid parameters!");
            return false;
        }
        std::string unitName{ Utils::toLowerCase(fileName) };
        std::string camelCaseName{ std::string(1, std::toupper(fileName[0])) + fileName.substr(1) };
        std::string className{ "T" + camelCaseName + "Service" };
        std::string sourcePath{ dirName };

        if (sourcePath.empty() || sourcePath == ".")
        {
            sourcePath = "./";
        }

        if (!std::filesystem::exists(sourcePath))
        {
            std::filesystem::create_directories(sourcePath);
        }
        std::string templateFilePath{ cli->pathTemp() + "/service.pasgen" };
        std::string templateFileName{ sourcePath + "/" + unitName + ".service.pas" };
        std::string templateContent{ Utils::readFromFile(templateFilePath) };
        std::string modifiedContent{ Utils::replaceString(templateContent, "{unitName}", unitName) };
        modifiedContent = Utils::replaceString(modifiedContent, "{serviceName}", className);

        bool isSuccess{ Utils::writeToFile(templateFileName, modifiedContent) };
        if (isSuccess)
        {
            Print::printCreate("CREATE", templateFileName, Utils::getSizeFile(templateFileName));
            // List Update DPR
            std::string update;
            cli->setUpdate(update.append("  ")
                .append(unitName)
                .append(".service in \'src\\modules\\")
                .append(fileName)
                .append("\\")
                .append(unitName)
                .append(".service.pas\',"));
        }
        return isSuccess;
    };
}