#pragma once

#ifndef CLIMAIN_H
#define CLIMAIN_H

#include <iostream>
#include <cstring>
#include "clibr.interfaces.h"

namespace clibr
{
    void cliMain(const int argc, char* argv[]);

    class ResourceHandler
    {
    public:
        ResourceHandler(ICli* cli, ICommand* updateExecute);
        ~ResourceHandler();
    private:
        ICli* _cli;
        ICommand* _updateExecute;
    };
}

#endif  //CLIMAIN_H
