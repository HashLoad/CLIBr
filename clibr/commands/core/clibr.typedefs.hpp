#pragma once

#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <map>
#include <list>
#include <vector>
#include <string>

namespace clibr
{
	struct CommandPair;

	typedef std::map<const std::string, CommandPair*> MapOptions;
	typedef std::map<const std::string, const MapOptions&> MapCommands;
	typedef std::map<const std::string, bool> MapTags;
	typedef std::vector<std::string> ListUpdates;
	typedef std::vector<std::string> ListOptions;
	typedef std::vector<std::string> ListText;
	typedef std::pair<const std::string, CommandPair*> forPair;
}

#endif // TYPEDEF_H