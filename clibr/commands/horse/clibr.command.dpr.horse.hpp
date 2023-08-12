#pragma once

#ifndef COMMANDHORSEDPR_H
#define COMMANDHORSEDPR_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandGenerateProjectHorse : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateProjectHorse() override = default;
	};
}

#endif // COMMANDHORSEDPR_H