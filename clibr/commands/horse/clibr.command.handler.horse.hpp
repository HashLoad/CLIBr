#pragma once

#ifndef COMMANDHORSEHANDLER_H
#define COMMANDHORSEHANDLER_H

#include "../../clibr.pch.hpp"

namespace clibr
{
	class CommandRouteHandlerHorse : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandRouteHandlerHorse() override = default;
	};
}

#endif // COMMANDHORSEHANDLER_H