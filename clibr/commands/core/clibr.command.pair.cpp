#include <memory>
#include "clibr.command.pair.hpp"
#include "../../clibr.interfaces.hpp"

namespace clibr 
{
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
