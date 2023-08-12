#pragma once

#ifndef COMMANDDFMVCL_H
#define COMMANDDFMVCL_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandGenerateFormVCL : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandGenerateFormVCL() override = default;
	};
}

#endif // COMMANDDFMVCL_H