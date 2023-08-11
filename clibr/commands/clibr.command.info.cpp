#include <iostream>
#include <string>
#include <vector>
#include "clibr.command.info.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

namespace clibr
{
    bool CommandInfo::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        ListText printText;
        printText.reserve(13);
        std::string version = "  Version: " + Utils::version();
        printText.push_back(" ______   ____    ____  ________  ______              ______  _____     _____  ");
        printText.push_back("|_   _ `. |_  \\  /   _||_   __  ||_   _ \\           .\' ___  ||_   _|   |_   _| ");
        printText.push_back("  | | `. \\ |   \\/   |    | |_ \\_|  | |_) | _ .--.  / .\'   \\_|  | |       | |   ");
        printText.push_back("  | |  | | | |\\  /| |    |  _|     |  __\'.[ `/\'`\\] | |         | |   _   | |   ");
        printText.push_back(" _| |_.\' /_| |_\\/_| |_  _| |_     _| |__) || |     \\ `.___.\'\\ _| |__/ | _| |_  ");
        printText.push_back("|______.\'|_____||_____||_____|   |_______/[___]     `.____ .\'|________||_____| ");
        printText.push_back("");
        printText.push_back(version);
        printText.push_back("  Author: Isaque Pinheiro");
        printText.push_back("  Email: isaquesp@gmail.com");
        printText.push_back("  Github: https://github.com/HashLoad/DMFBr");
        printText.push_back("  Documentation: https://dmfbr-en.docs-br.com");
        printText.push_back("");

        Print::printHelp(Utils::join(printText, '\n'));
        return true;
    };
}