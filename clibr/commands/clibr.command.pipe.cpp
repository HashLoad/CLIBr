#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.pipe.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandTransformPipe::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        if (fileName.empty())
        {
            Print::printAlert("Invalid parameters!");
            return false;
        }
        std::string unitName{ Utils::toLowerCase(fileName) };
        std::string camelCaseName{ std::string(1, std::toupper(fileName[0])) + fileName.substr(1) };
        std::string className{ "TParse" + camelCaseName + "Pipe" };
        std::string sourcePath{ dirName };

        if (sourcePath.empty() || sourcePath == ".")
        {
            sourcePath = "./src/pipes/" + fileName;
        }

        if (std::filesystem::exists(sourcePath))
        {
            std::filesystem::create_directories(sourcePath);
        }
        std::string templateFilePath{ cli->pathTemp() + "/pipe.pasgen" };
        std::string templateFileName{ dirName + "/" + unitName + ".dpr" };
        std::string templateContent{ Utils::readFromFile(templateFilePath) };
        std::string modifiedContent{ Utils::replaceString(templateContent, "{pipeName}", className) };

        bool isSuccess{ Utils::writeToFile(templateFileName, modifiedContent) };

        if (isSuccess)
        {
            Print::printCreate("CREATE", templateFileName, Utils::getSizeFile(templateFileName));
            // List Update DPR
            std::string update;
            cli->setUpdate(update.append("  ")
                .append(unitName)
                .append(".pipes in \'src\\pipes\\")
                .append(fileName)
                .append("\\")
                .append(unitName)
                .append(".pipe.pas\',"));
        }
        return isSuccess;
    };
}