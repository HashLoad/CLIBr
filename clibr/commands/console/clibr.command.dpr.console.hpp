#pragma once

#ifndef COMMANDCONSOLEDPR_H
#define COMMANDCONSOLEDPR_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandGenerateProjectConsole : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateProjectConsole() override = default;
	};
}

#endif // COMMANDCONSOLEDPR_H