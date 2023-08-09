#include "../../clibr.interfaces.hpp"
#include "clibr.command.pair.hpp"

clibr::CommandPair::CommandPair() : command(nullptr) {}
clibr::CommandPair::CommandPair(clibr::ICommand* value) : command(value) {}

clibr::CommandPair::~CommandPair()
{
	delete command;
}

clibr::ICommand* clibr::CommandPair::getCommand()
{
	return command;
}

void clibr::CommandPair::setCommand(clibr::ICommand* value)
{
    delete command;
    command = value;
}

