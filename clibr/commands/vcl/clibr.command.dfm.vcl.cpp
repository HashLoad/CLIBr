#include <iostream>
#include <string>
#include "clibr.command.dfm.vcl.h"
#include "../core/clibr.utils.h"
#include "../core/clibr.print.h"
#include "../../clibr.interfaces.h"

bool clibr::CommandGenerateFormVCL::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName = clibr::Utils::toLowerCase(fileName);
    std::string templateFilePath = cli->pathTemp() + "/vcl.project.form.pas";
    std::string templateFileName = dirName + "/u" + unitName + ".dfm";
    std::string templateContent = clibr::Utils::readFromFile(templateFilePath);

    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }

    bool success = clibr::Utils::writeToFile(templateFileName, templateContent);
    if (success)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
    }
    return success;
};

clibr::CommandGenerateFormVCL::~CommandGenerateFormVCL(){};
