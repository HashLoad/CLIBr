#pragma once

#ifndef COMMANDHORSEHANDLER_H
#define COMMANDHORSEHANDLER_H

#include <string>
#include "../../clibr.interfaces.h"

namespace clibr
{
	class CommandRouteHandlerHorse : public ICommand
	{
	public:
		bool execute(const std::string& dirName, const std::string& fileName,
			ICli* cli) override;
		~CommandRouteHandlerHorse() override;
	};
}

#endif // COMMANDHORSEHANDLER_H