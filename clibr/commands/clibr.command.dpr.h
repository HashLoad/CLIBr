#pragma once

#ifndef _COMMANDUPDATEDPR_H
#define _COMMANDUPDATEDPR_H

#include <string>
#include "../clibr.interfaces.h"

class CommandUpdateDpr : public ICommand
{
public:
	bool execute(const std::string& dirName, const std::string& fileName,
		const ICli* cli) override;
	~CommandUpdateDpr() override;
};

#endif // _COMMANDUPDATEDPR_H