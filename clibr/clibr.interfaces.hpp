#pragma once

#ifndef INTERFACES_H
#define INTERFACES_H

#include <map>
#include <string>
#include "commands/core/clibr.typedefs.hpp"

namespace clibr
{
    /// <summary>
    /// Base interface for Command-Line Interface (CLI) functionality.
    /// </summary>
    class ICli
    {
    public:
        /// <summary>
        /// Gets the temporary path used by the CLI.
        /// </summary>
        /// <returns>A constant reference to the temporary path string.</returns>
        virtual const std::string& pathTemp() const = 0;

        /// <summary>
        /// Gets the last executed command.
        /// </summary>
        /// <returns>A constant reference to the last executed command string.</returns>
        virtual const std::string& commandExecuted() const = 0;

        /// <summary>
        /// Gets the map of available commands.
        /// </summary>
        /// <returns>A constant reference to the map of commands.</returns>
        virtual const clibr::MapCommands& commands() const = 0;

        /// <summary>
        /// Gets the map of internal options.
        /// </summary>
        /// <returns>A constant reference to the map of internal options.</returns>
        virtual const clibr::MapOptions& optionsInternal() const = 0;

        /// <summary>
        /// Gets the map of tags used by the CLI.
        /// </summary>
        /// <returns>A constant reference to the map of tags.</returns>
        virtual const clibr::MapTags& tags() const = 0;

        /// <summary>
        /// Gets the list of updates made by the CLI.
        /// </summary>
        /// <returns>A constant reference to the list of updates.</returns>
        virtual const clibr::ListUpdates& updates() const = 0;

        /// <summary>
        /// Sets the value of the last executed command.
        /// </summary>
        /// <param name="value">The value to set as the last executed command.</param>
        virtual void commandExecuted(const std::string& value) = 0;

        /// <summary>
        /// Sets the value of a tag in the CLI.
        /// </summary>
        /// <param name="name">The name of the tag to set.</param>
        /// <param name="value">The value to set for the tag.</param>
        virtual void setTagValue(const std::string& name, const bool value) = 0;

        /// <summary>
        /// Sets the value for updates made by the CLI.
        /// </summary>
        /// <param name="value">The value to set for updates.</param>
        virtual void setUpdate(const std::string& value) = 0;

        /// <summary>
        /// Virtual destructor to ensure proper destruction of derived classes.
        /// </summary>
        virtual ~ICli() = default;
    };

    /// <summary>
    /// Base interface for executable commands.
    /// </summary>
    class ICommand
    {
    public:
        /// <summary>
        /// Executes the command.
        /// </summary>
        /// <param name="dirName">The directory name.</param>
        /// <param name="fileName">The file name.</param>
        /// <param name="cli">A pointer to the ICli object providing information and functionality to the command.</param>
        /// <returns>True if the execution is successful, false otherwise.</returns>
        virtual bool execute(const std::string& dirName, const std::string& fileName, ICli* cli) = 0;

        /// <summary>
        /// Virtual destructor to ensure proper destruction of derived classes.
        /// </summary>
        virtual ~ICommand() = default;
    };
}

#endif // INTERFACES_H
