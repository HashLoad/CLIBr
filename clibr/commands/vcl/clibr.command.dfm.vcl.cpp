#include <iostream>
#include <string>
#include "clibr.command.dfm.vcl.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandGenerateFormVCL::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        std::string unitName{ Utils::toLowerCase(fileName) };
        std::string templateFilePath{ cli->pathTemp() + "/vcl.project.form.pas" };
        std::string templateFileName{ dirName + "/u" + unitName + ".dfm" };
        std::string templateContent{ Utils::readFromFile(templateFilePath) };

        if (fileName.empty())
        {
            Print::printAlert("Invalid parameters!");
            return false;
        }

        bool isSuccess{ Utils::writeToFile(templateFileName, templateContent) };
        if (isSuccess)
        {
            Print::printCreate("CREATE", templateFileName, Utils::getSizeFile(templateFileName));
        }
        return isSuccess;
    };

    CommandGenerateFormVCL::~CommandGenerateFormVCL() {};
}