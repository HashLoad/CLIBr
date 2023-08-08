#pragma once

#ifndef COMMANDPAIR_H
#define COMMANDPAIR_H

#include "../../clibr.interfaces.h"

namespace clibr
{
	class CommandPair
	{
	public:
		CommandPair();
		CommandPair(ICommand* value);
		~CommandPair();

		ICommand* getCommand();
		void setCommand(ICommand* value);
	private:
		ICommand* command;
	};
}

#endif // COMMANDPAIR_H

