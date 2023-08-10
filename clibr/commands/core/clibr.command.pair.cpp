#include <memory>
#include "../../clibr.interfaces.hpp"
#include "clibr.command.pair.hpp"

clibr::CommandPair::CommandPair() : command(nullptr) {}
clibr::CommandPair::CommandPair(std::shared_ptr<clibr::ICommand> value) : command(value) {}

std::shared_ptr<clibr::ICommand> clibr::CommandPair::getCommand()
{
	return command;
}

void clibr::CommandPair::setCommand(std::shared_ptr<clibr::ICommand> value)
{
    command = std::move(value);
}

