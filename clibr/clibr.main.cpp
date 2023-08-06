#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include "core/clibr.command.pair.h"
#include "commands/clibr.command.dpr.h"
#include "clibr.interfaces.h"
#include "clibr.cli.h"
#include "clibr.main.h"

void cliMain(int argc, char* argv[])
{
    std::filesystem::path pathCLI = std::filesystem::current_path();
    std::string pathFormated = pathCLI.string();
    std::replace(pathFormated.begin(), pathFormated.end(), '\\', '/');
    std::list<std::string> options;
    std::map<std::string, CommandPair*> commandOptions;
    std::string dirName = "";
    std::string fileName = "";
    bool isSuccess = false;
    // CLI
    ICli* cli = new Cli(pathFormated);
    ICommand* updateExecute = new CommandUpdateDpr();

    for (int LFor = 1; LFor < argc; LFor++) {
        if (cli->commands().count(argv[LFor]) > 0) {
            commandOptions = cli->commands().at(argv[LFor]);
            cli->commandExecuted(argv[LFor]);
            break;
        }
    }

    for (int LFor = 1; LFor < argc; LFor++) {
        const std::string item = argv[LFor];
        if (cli->commands().count(item) > 0) {
            options.push_back(item);
        } else if (cli->tags().count(item) > 0) {
            cli->tags()[item] = true;
        } else {
            std::filesystem::path filePath(argv[LFor]);
            std::string dirName = filePath.parent_path().string();
            std::string fileName = filePath.filename().string();
        }
	}

    for (std::string& item : options) {
        if (commandOptions.count(item) > 0 &&
            commandOptions[item]->getCommand() != nullptr)
        {
            bool isSuccess = commandOptions[item]->getCommand()->execute(
                dirName, fileName, cli);
            if (isSuccess) {
                break;
            }
        }
    }
    options.clear();
    commandOptions.clear();

    delete updateExecute;
    delete cli;

    if (!isSuccess) {
        //Utils.printAlert('Run \'clibr --help\' for usage.');
        return;
    }
    // Updates execute
    if (!cli->updates().empty()) {
		//updateExecute.execute(dirName, fileName, cli);
	}
}

