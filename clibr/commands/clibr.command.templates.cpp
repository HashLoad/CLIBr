#include <iostream>
#include <string>
#include "clibr.command.templates.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandTemplates::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        ListText printText;
        printText.reserve(21);
        printText.push_back("|----------------------|");
        printText.push_back("| CLIBr - Templates    |");
        printText.push_back("|----------------------|-------------------------------------------|");
        printText.push_back("|        Name          |               Descripton                  |");
        printText.push_back("|----------------------|-------------------------------------------|");
        printText.push_back("| handler.pas          | Default Route Handler                     |");
        printText.push_back("| module.app.pas       | Default Application Module                |");
        printText.push_back("| module.pas           | Default Modules                           |");
        printText.push_back("| controller.pas       | Default Controller                        |");
        printText.push_back("| service.pas          | Default Service                           |");
        printText.push_back("| vcl.project.pas      | Default VCL Server Project                |");
        printText.push_back("| vcl.project.unit.pas | Default VCL Server Unit                   |");
        printText.push_back("| vcl.project.form.pas | Default VCL Server Form                   |");
        printText.push_back("| console.projetc.pas  | Default Console Project                   |");
        printText.push_back("| horse.project.pas    | Horse Pattern Projec                      |");
        printText.push_back("| horse.handler.pas    | Horse Pattern Route Handler               |");
        printText.push_back("| body.pas             | Guad Routes Body                          |");
        printText.push_back("| header.pas           | Guad Routes Header                        |");
        printText.push_back("| pipe.pas             | Pipe (Transformation/Validation)          |");
        printText.push_back("|----------------------|-------------------------------------------|");
        printText.push_back("");

        Print::printHelp(Utils::join(printText, '\n'));
        return true;
    };
}