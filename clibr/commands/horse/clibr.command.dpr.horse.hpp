#pragma once

#ifndef COMMANDHORSEDPR_H
#define COMMANDHORSEDPR_H

#include <string>
#include "../../clibr.interfaces.hpp"

namespace clibr
{
	class CommandGenerateProjectHorse : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateProjectHorse() override;
	};
}

#endif // COMMANDHORSEDPR_H