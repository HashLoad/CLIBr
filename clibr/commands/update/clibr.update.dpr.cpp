#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "clibr.update.dpr.h"
#include "../core/clibr.utils.h"
#include "../core/clibr.print.h"
#include "../../clibr.interfaces.h"

bool clibr::CommandUpdateDpr::execute(
    const std::string& dirName, const std::string& fileName, clibr::ICli* cli)
{
    std::filesystem::path currentDir = std::filesystem::current_path() / dirName;
    currentDir = std::filesystem::canonical(currentDir);

    std::vector<std::filesystem::directory_entry> files;

    for (const auto& entry : std::filesystem::directory_iterator(currentDir))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".dpr") 
        {
            files.push_back(entry);
        }
    }

    std::string dprFilePath = "";
    for (const auto& file : files)
    {
        if (file.path().extension() == ".dpr") 
        {
            dprFilePath = file.path().string();
            break;
        }
    }

    if (dprFilePath.empty()) 
    {
        return false;
    }

    std::ifstream fileProject(dprFilePath);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(fileProject, line)) 
    {
        lines.push_back(line);
    }

    size_t usesIndex = -1;
    for (size_t iFor = 0; iFor < lines.size(); iFor++) 
    {
        if (lines[iFor].find("uses") != std::string::npos) 
        {
            usesIndex = iFor;
            break;
        }
    }

    if (usesIndex == -1)
    {
        clibr::Print::printAlert("Error: 'uses' clause not found in the DPR file.");
        return false;
    }

    size_t semicolonIndex = -1;
    for (size_t iFor = usesIndex + 1; iFor < lines.size(); iFor++) 
    {
        if (lines[iFor].find(';') != std::string::npos)
        {
            semicolonIndex = iFor;
            break;
        }
    }

    if (semicolonIndex == -1)
    {
        clibr::Print::printAlert("Error: Semicolon not found after the 'uses' clause in the DPR file.");
        return false;
    }
    lines[semicolonIndex] = lines[semicolonIndex].replace(lines[semicolonIndex].find(';'), 1, ",");

    for (const std::string& unitName : cli->updates()) 
    {
        if (std::find(lines.begin(), lines.end(), unitName) != lines.end()) 
        {
            continue;
        }
        semicolonIndex++;
        lines.insert(lines.begin() + semicolonIndex, unitName);
    }

    lines[semicolonIndex] = lines[semicolonIndex].replace(lines[semicolonIndex].find(','), 1, ";");

    std::ofstream outputFile(dprFilePath);
    for (const std::string& updatedLine : lines) 
    {
        outputFile << updatedLine << "\n";
    }
    outputFile.close();
    
    std::string update;
    clibr::Print::printUpdate("UPDATE", update.append(dirName)
        .append("/")
        .append(files[0].path().filename().string()), clibr::Utils::getSizeFile(dprFilePath));

    return true;
}

clibr::CommandUpdateDpr::~CommandUpdateDpr(){};
