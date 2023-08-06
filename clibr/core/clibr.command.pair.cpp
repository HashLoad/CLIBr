#include "../clibr.interfaces.h"
#include "clibr.command.pair.h"

CommandPair::CommandPair() : command(nullptr) {}
CommandPair::CommandPair(ICommand* value) : command(value) {}

CommandPair::~CommandPair()
{
	delete command;
}

ICommand* CommandPair::getCommand()
{
	return command;
}

void CommandPair::setCommand(ICommand* value)
{
    delete command;
    command = value;
}

