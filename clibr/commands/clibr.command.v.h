#pragma once

#ifndef _COMMANDVERSION_H
#define _COMMANDVERSION_H

#include <string>
#include "../clibr.interfaces.h"

class CommandVersion : public ICommand
{
  public:
    bool execute(const std::string &dirName, const std::string &fileName,
		const ICli* cli) override;
	~CommandVersion() override;
};

#endif // _COMMANDVERSION_H

