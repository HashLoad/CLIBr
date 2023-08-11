#include <memory>
#include "../../clibr.interfaces.hpp"
#include "clibr.command.pair.hpp"

namespace clibr 
{
	CommandPair::CommandPair() : command(nullptr) {}
	CommandPair::CommandPair(std::shared_ptr<ICommand> value) : command(value) {}

	std::shared_ptr<ICommand> CommandPair::getCommand()
	{
		return command;
	}

	void CommandPair::setCommand(std::shared_ptr<ICommand> value)
	{
		command = std::move(value);
	}
}
