#pragma once

#ifndef COMMANDUPDATEDPR_H
#define COMMANDUPDATEDPR_H

#include <string>
#include "../../clibr.interfaces.h"

namespace clibr
{
	class CommandUpdateDpr : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName, 
			ICli* cli) override;
		~CommandUpdateDpr() override;
	};
}

#endif // COMMANDUPDATEDPR_H