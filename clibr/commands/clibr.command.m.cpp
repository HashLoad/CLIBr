#include <filesystem>
#include "clibr.command.m.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.pch.hpp"

namespace clibr
{
    bool CommandModule::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        if (fileName.empty())
        {
            Print::printAlert("Invalid parameters!");
            return false;
        }
        std::string unitName{ Utils::toLowerCase(fileName) };
        std::string camelCaseName{ std::string(1, std::toupper(fileName[0])) + fileName.substr(1) };
        std::string className{ "T" + camelCaseName + "Module" };
        std::string sourcePath{ dirName };
        bool isAppModule{ (unitName == "app") };
        bool isGuard{ false };

        if (sourcePath.empty() || sourcePath == ".")
        {
            sourcePath = "./src/modules/" + fileName;
        }

        if (!std::filesystem::exists(sourcePath))
        {
            bool isCreate{ std::filesystem::create_directories(sourcePath) };
        }

        std::string templateFilePath{ "" };
        isAppModule ? templateFilePath = cli->pathTemp() + "/module.app.pas" :
            templateFilePath = cli->pathTemp() + "/module.pas";
        std::string templateFileName{ sourcePath + "/" + unitName + ".module.pas" };
        std::string templateContent{ Utils::readFromFile(templateFilePath) };
        std::string modifiedContent{ Utils::replaceString(templateContent, "{moduleName}", className) };
        modifiedContent = Utils::replaceString(modifiedContent, "{unitName}", unitName);
        modifiedContent = Utils::replaceString(modifiedContent, "{className}", camelCaseName);

        // Guard exist
        isGuard = _argGuardExist(cli);
        if (isGuard) {
            modifiedContent = Utils::replaceString(modifiedContent, "{guardCode}",
                _generateGuardBody(camelCaseName, cli));
            modifiedContent = Utils::replaceString(modifiedContent, "{guardHeader}",
                _generateGuardHeader(camelCaseName, cli));
        }

        bool success = Utils::writeToFile(templateFileName, modifiedContent);
        if (success)
        {
            Print::printCreate("CREATE", templateFileName, Utils::getSizeFile(templateFileName));
            // List Update DPR
            std::string update;
            cli->setUpdate(update.append("  ")
                .append(unitName)
                .append(".module in \'src\\modules\\")
                .append(fileName)
                .append("\\")
                .append(unitName)
                .append(".module.pas\',"));
        }
        return success;
    };

    bool CommandModule::_argGuardExist(const ICli* cli)
    {
        const MapTags& tags = cli->tags();
        return tags.at("--guard") || tags.at("-gu");
    }

    std::string CommandModule::_generateGuardBody(const std::string& camelCaseName, const ICli* cli)
    {
        std::string templateFilePath = cli->pathTemp() + "/" + "body.pas";
        std::string templateContent = Utils::readFromFile(templateFilePath);
        std::string modifiedContent = Utils::replaceString(templateContent, "{className}", "T" + camelCaseName);

        return modifiedContent;
    }

    std::string CommandModule::_generateGuardHeader(const std::string& camelCaseName, const ICli* cli)
    {
        std::string templateFilePath = cli->pathTemp() + "/" + "header.pas";
        std::string templateContent = Utils::readFromFile(templateFilePath);
        std::string modifiedContent = Utils::replaceString(templateContent, "{className}", "T" + camelCaseName);

        return modifiedContent;

    }
}