#pragma once

#ifndef _INTERFACES_H
#define _INTERFACES_H

#include <map>
#include <list>
#include <string>

class CommandPair;

class ICli
{
  public:
    virtual std::string& pathCLI() = 0;
    virtual std::string& commandExecuted() = 0;
    virtual std::map<std::string, std::map<std::string, CommandPair*>&>& commands() = 0;
    virtual std::map<std::string, CommandPair*>& optionsInternal() = 0;
    virtual std::map<std::string, bool>& tags() = 0;
    virtual std::list<std::string>& updates() = 0;
    virtual void commandExecuted(const std::string& value) = 0;
	virtual ~ICli() = 0;
};

class ICommand
{
  public:
	virtual bool execute(const std::string &dirName,
		const std::string &fileName, const ICli* cli) = 0;
	virtual ~ICommand() = 0;
};

#endif // _INTERFACES_H
