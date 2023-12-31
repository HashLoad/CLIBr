#pragma once

#ifndef COMMANDPASVCL_H
#define COMMANDPASVCL_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandGenerateUnitVCL : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateUnitVCL() override = default;
	};
}

#endif // COMMANDPASVCL_H