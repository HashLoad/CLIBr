#pragma once

#ifndef _COMMANDPAIR_H
#define _COMMANDPAIR_H

#include "../clibr.interfaces.h"

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

#endif // _COMMANDPAIR_H

