#pragma once

#ifndef COMMANDCONSOLEDPR_H
#define COMMANDCONSOLEDPR_H

#include <string>
#include "../../clibr.interfaces.h"

namespace clibr
{
	class CommandGenerateProjectConsole : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateProjectConsole() override;
	};
}

#endif // COMMANDCONSOLEDPR_H