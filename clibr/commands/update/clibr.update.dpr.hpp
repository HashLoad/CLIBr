#pragma once

#ifndef COMMANDUPDATEDPR_H
#define COMMANDUPDATEDPR_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandUpdateDpr : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName, 
			ICli* cli) override;
		~CommandUpdateDpr() override = default;
	};
}

#endif // COMMANDUPDATEDPR_H