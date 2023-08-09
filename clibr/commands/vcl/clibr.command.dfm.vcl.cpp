#include <iostream>
#include <string>
#include "clibr.command.dfm.vcl.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.interfaces.hpp"

bool clibr::CommandGenerateFormVCL::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::string unitName{ clibr::Utils::toLowerCase(fileName) };
    std::string templateFilePath{ cli->pathTemp() + "/vcl.project.form.pas" };
    std::string templateFileName{ dirName + "/u" + unitName + ".dfm" };
    std::string templateContent{ clibr::Utils::readFromFile(templateFilePath) };

    if (fileName.empty())
    {
        clibr::Print::printAlert("Invalid parameters!");
        return false;
    }

    bool isSuccess{ clibr::Utils::writeToFile(templateFileName, templateContent) };
    if (isSuccess)
    {
        clibr::Print::printCreate("CREATE", templateFileName, clibr::Utils::getSizeFile(templateFileName));
    }
    return isSuccess;
};

clibr::CommandGenerateFormVCL::~CommandGenerateFormVCL(){};
