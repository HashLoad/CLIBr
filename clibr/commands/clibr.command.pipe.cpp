#include <iostream>
#include <string>
#include <filesystem>
#include "clibr.command.pipe.h"
#include "core/clibr.utils.h"
#include "core/clibr.print.h"
#include "../clibr.interfaces.h"

bool clibr::CommandTransformPipe::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName = clibr::Utils::toLowerCase(fileName);
    std::string camelCaseName = std::string(1, std::toupper(fileName[0])) + fileName.substr(1);
    std::string className = "TParse" + camelCaseName + "Pipe";
    std::string sourcePath = dirName;

    if (sourcePath.empty() || sourcePath == ".")
    {
        sourcePath = "./src/pipes/" + fileName;
    }

    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }

    if (std::filesystem::exists(sourcePath))
    {
        std::filesystem::create_directories(sourcePath);
    }
    std::string templateFilePath = cli->pathCLI() + "/pipe.pas";
    std::string templateFileName = dirName + "/" + unitName + ".dpr";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);
    std::string modifiedContent = clibr::Utils::replaceString(templateContent, "{pipeName}", className);

    bool success = clibr::Utils::writeToFile(templateFileName, modifiedContent);

    if (success)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
        // List Update DPR
        std::string update;
        cli->updates().push_back(update.append("  ")
            .append(unitName)
            .append(".pipes in \'src\\pipes\\")
            .append(fileName)
            .append("\\")
            .append(unitName)
            .append(".pipe.pas\'")
            .append(","));
    }
    return success;
};

clibr::CommandTransformPipe::~CommandTransformPipe() {};
