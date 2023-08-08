#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include "commands/update/clibr.update.dpr.h"
#include "commands/core/clibr.command.pair.h"
#include "commands/core/clibr.typedefs.h"
#include "commands/core/clibr.print.h"
#include "commands/core/clibr.typedefs.h"
#include "clibr.interfaces.h"
#include "clibr.cli.h"
#include "clibr.main.h"

namespace sfs = std::filesystem;

clibr::ResourceHandler::ResourceHandler(clibr::ICli* cli, clibr::ICommand* updateExecute)
        : _cli(cli), _updateExecute(updateExecute) {}

clibr::ResourceHandler::~ResourceHandler()
{
    delete _updateExecute;
    delete _cli;
};

void clibr::cliMain(const int argc, char* argv[])
{
    sfs::path executablePath(argv[0]);
    sfs::path pathCLI = executablePath.parent_path();
    std::string pathFormated = pathCLI.string() + "/templates";
    std::replace(pathFormated.begin(), pathFormated.end(), '\\', '/');
    clibr::ListOptions options;
    clibr::MapOptions commandOptions;
    std::string dirName = "";
    std::string fileName = "";
    bool isSuccess = false;
    clibr::ICli* cli = new clibr::Cli(pathFormated);
    clibr::ICommand* updateExecute = new clibr::CommandUpdateDpr();
    // Auto destroy (delete cli and updateExecute pointer)
    clibr::ResourceHandler resourceHandler(cli, updateExecute);

    // Command find
    for (int LFor = 1; LFor < argc; LFor++)
    {
        if (cli->commands().count(argv[LFor]) > 0)
        {
            commandOptions = cli->commands().at(argv[LFor]);
            cli->commandExecuted(argv[LFor]);
            break;
        }
    }

    // Arguments find
    for (int LFor = 1; LFor < argc; LFor++)
    {
        const std::string item = argv[LFor];
        if (cli->commands().count(item) > 0)
        {
            options.push_back(item);
        }
        else if (cli->tags().count(item) > 0)
        {
            cli->tags().at(item) = true;
        }
        else
        {
            std::filesystem::path filePath(argv[LFor]);
            dirName = filePath.parent_path().string();
            fileName = filePath.filename().string();
        }
    }

    // Execute
    for (std::string& item : options)
    {
        if (commandOptions.count(item) == 0 &&
            commandOptions[item]->getCommand() == nullptr)
        {
            continue;
        }

        clibr::ICommand* command = commandOptions[item]->getCommand();
        if (auto specificCommand = dynamic_cast<clibr::ICommand*>(command))
        {
            isSuccess = specificCommand->execute(dirName, fileName, cli);
            if (isSuccess)
            {
                break;
            }
        }
    }

    if (isSuccess && !cli->updates().empty())
    {
        isSuccess = updateExecute->execute(dirName, fileName, cli);
    }
    else if (!isSuccess)
    {
        clibr::Print::printAlert("Run \'clibr --help\' for usage.");
    }
    options.clear();
    commandOptions.clear();
};