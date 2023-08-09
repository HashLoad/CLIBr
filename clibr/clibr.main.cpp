#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include "commands/update/clibr.update.dpr.hpp"
#include "commands/core/clibr.command.pair.hpp"
#include "commands/core/clibr.typedefs.hpp"
#include "commands/core/clibr.print.hpp"
#include "commands/core/clibr.typedefs.hpp"
#include "clibr.interfaces.hpp"
#include "clibr.cli.hpp"
#include "clibr.main.hpp"

namespace sfs = std::filesystem;

void clibr::cliMain(const int argc, char* argv[])
{
    sfs::path executablePath(argv[0]);
    sfs::path pathCLI { executablePath.parent_path() };
    std::string pathFormated { pathCLI.string() + "/templates" };
    std::replace(pathFormated.begin(), pathFormated.end(), '\\', '/');
    std::string dirName { "" };
    std::string fileName { "" };
    std::shared_ptr<clibr::ICli> cli { std::make_shared<clibr::Cli>(pathFormated) };
    clibr::ListOptions options;
    clibr::MapOptions commandOptions;
    bool isSuccess { false };

    // Command find
    for (int LFor = 1; LFor < argc; LFor++)
    {
        if (cli->commands().contains(argv[LFor]))
        {
            commandOptions = cli->commands().at(argv[LFor]);
            cli->commandExecuted(argv[LFor]);
            break;
        }
    }

    // Arguments find
    for (int LFor = 1; LFor < argc; LFor++)
    {
        const std::string item{ argv[LFor] };
        if (commandOptions.contains(item))
        {
            options.push_back(item);
        }
        else if (cli->tags().contains(item))
        {
            cli->setTagValue(item, true);
        }
        else
        {
            std::filesystem::path filePath(argv[LFor]);
            dirName = filePath.parent_path().string();
            fileName = filePath.filename().string();
            if (dirName.empty())
            {
                dirName = ".";
            }
        }
    }
    
    // Execute
    for (const std::string& item : options)
    {
        if (commandOptions.contains(item) &&
            commandOptions[item] == nullptr)
        {
            continue;
        }

        clibr::ICommand* command{ commandOptions[item]->getCommand() };
        if (auto specificCommand = dynamic_cast<clibr::ICommand*>(command))
        {
            isSuccess = specificCommand->execute(dirName, fileName, cli.get());
            if (isSuccess)
            {
                break;
            }
        }
    }

    if (isSuccess && !cli->updates().empty())
    {
        std::shared_ptr<clibr::ICommand> updateExecute = std::make_shared<clibr::CommandUpdateDpr>();
        isSuccess = updateExecute->execute(dirName, fileName, cli.get());
    }

    if (!isSuccess)
    {
       clibr::Print::printAlert("Run \'clibr --help\' for usage.");
    }
    options.clear();
    commandOptions.clear();
};