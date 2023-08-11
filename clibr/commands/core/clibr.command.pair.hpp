#pragma once

#ifndef COMMANDPAIR_H
#define COMMANDPAIR_H

#include <memory>
#include "../../clibr.interfaces.hpp"

namespace clibr
{
/*
	class CommandPair
	{
	public:
		CommandPair();
		CommandPair(std::shared_ptr<ICommand> value);
		~CommandPair() = default;

		std::shared_ptr<ICommand> getCommand();
		void setCommand(std::shared_ptr<ICommand> value);
	private:
		std::shared_ptr<ICommand> command;
	};
*/

	struct CommandPair
	{
		std::shared_ptr<ICommand> command;

		CommandPair();
		CommandPair(std::shared_ptr<ICommand> value);
		~CommandPair() = default;

		std::shared_ptr<ICommand> getCommand();
		void setCommand(std::shared_ptr<ICommand> value);
	};
}

#endif // COMMANDPAIR_H

