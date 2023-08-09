#include <iostream>
#include <string>
#include "clibr.command.h.hpp"
#include "core/clibr.utils.hpp"
#include "core/clibr.print.hpp"
#include "../clibr.interfaces.hpp"

bool clibr::CommandHelp::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    if (cli->commandExecuted() == "generate" || cli->commandExecuted() == "g") {
        _executeInternalG();
    }
    else if (cli->commandExecuted() == "new" || cli->commandExecuted() == "n") {
        _executeInternalN();
    }
    else {
        _executeInternal();
    }
    return true;
};

clibr::CommandHelp::~CommandHelp() {};

void clibr::CommandHelp::_executeInternal() {

    clibr::ListText printText;
    printText.reserve(23);
    printText.push_back("CLIBr");
    printText.push_back("Usage: clibr <command> [argument] [filename] [tag]");
    printText.push_back("\u001b" "[36m" "commands:" "\u001b" "[0m");
    printText.push_back("  n, new           create new delphi project (console default)");
    printText.push_back("  g, generate      create new argument");
    printText.push_back("  v, version       show version");
    printText.push_back("  i, info          show informations");
    printText.push_back("  t, templates     show templates");
    printText.push_back("\u001b" "[31m" "arguments:" "\u001b" "[0m");
    printText.push_back("  app, application create new delphi project");
    printText.push_back("  handler          create route handle");
    printText.push_back("  module           create module");
    printText.push_back("  controller       create controller");
    printText.push_back("  service          create service");
    printText.push_back("  all              create all (handler, module, controller and service)");
    printText.push_back("\u001b" "[32m" "tags:" "\u001b" "[0m");
    printText.push_back("  --vcl            create new project VCL pattern");
    printText.push_back("  --horse          create new project Horse pattern (console)");
    printText.push_back("  -gu, --guard     add security guards");
    printText.push_back("  -h, --help       show help");
    printText.push_back("\u001b" "[33m" "For more information, please refer to the documentation." "\u001b" "[0m");
    printText.push_back("\u001b" "[34m" "https://dmfbr-en.docs-br.com" "\u001b" "[0m");
    printText.push_back("");

    clibr::Print::printHelp(clibr::Utils::join(printText, '\n'));
}

void clibr::CommandHelp::_executeInternalG() {

    clibr::ListText printText;
    printText.reserve(23);
    printText.push_back("CLIBr");
    printText.push_back("Usage: clibr g <argument> <filename> [tag]");
    printText.push_back("\u001b" "[35m" "commands:" "\u001b" "[0m");
    printText.push_back("  g, generate      generates the desired argument");
    printText.push_back("\u001b" "[31m" "arguments:" "\u001b" "[0m");
    printText.push_back("  handler          create route handle");
    printText.push_back("  module           create module");
    printText.push_back("  controller       create controller");
    printText.push_back("  service          create service");
    printText.push_back("  all              create all (handler, module, controller and service)");
    printText.push_back("\u001b" "[32m" "tags:" "\u001b" "[0m");
    printText.push_back("  --horse          create Horse pattern (console)");
    printText.push_back("  -gu, --guard     adds security guards");
    printText.push_back("  -h, --help       show help");
    printText.push_back("\u001b" "[36m" "samples:" "\u001b" "[0m");
    printText.push_back("  clibr g handler products");
    printText.push_back("  clibr g module products --horse --guard");
    printText.push_back("  clibr g controller products");
    printText.push_back("  clibr g service products");
    printText.push_back("  clibr g all products");
    printText.push_back("\u001b" "[33m" "For more information, please refer to the documentation." "\u001b" "[0m");
    printText.push_back("\u001b" "[34m" "https://dmfbr-en.docs-br.com" "\u001b" "[0m");
    printText.push_back("");

    clibr::Print::printHelp(clibr::Utils::join(printText, '\n'));
}

void clibr::CommandHelp::_executeInternalN() {

    clibr::ListText printText;
    printText.reserve(17);
    printText.push_back("CLIBr");
    printText.push_back("Usage: clibr n <argument> <filename> [tag]");
    printText.push_back("\u001b" "[32m" "commands:" "\u001b" "[0m");
    printText.push_back("  n, new           create new delphi project (console default)");
    printText.push_back("\u001b" "[31m" "arguments:" "\u001b" "[0m");
    printText.push_back("  app, application");
    printText.push_back("\u001b" "[35m" "tags:" "\u001b" "[0m");
    printText.push_back("  --horse          create Horse pattern");
    printText.push_back("  -gu, --guard     adds security guards");
    printText.push_back("  -h, --help       show help");
    printText.push_back("\u001b" "[36m" "samples:" "\u001b" "[0m");
    printText.push_back("  clibr n app app_ping");
    printText.push_back("  clibr n app app_ping --horse");
    printText.push_back("  clibr n app app_ping --guard");
    printText.push_back("\u001b" "[33m" "For more information, please refer to the documentation." "\u001b" "[0m");
    printText.push_back("\u001b" "[34m" "https://dmfbr-en.docs-br.com" "\u001b" "[0m");
    printText.push_back("");

    clibr::Print::printHelp(clibr::Utils::join(printText, '\n'));
}