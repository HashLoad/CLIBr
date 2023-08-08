#pragma once

#ifndef COMMANDDPRVCL_H
#define COMMANDDPRVCL_H

#include <string>
#include "../../clibr.interfaces.h"

namespace clibr
{
	class CommandGenerateProjectVCL : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateProjectVCL() override;
	};
}

#endif // COMMANDDPRVCL_H