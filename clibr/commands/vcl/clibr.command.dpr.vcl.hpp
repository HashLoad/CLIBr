#pragma once

#ifndef COMMANDDPRVCL_H
#define COMMANDDPRVCL_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandGenerateProjectVCL : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateProjectVCL() override = default;
	};
}

#endif // COMMANDDPRVCL_H