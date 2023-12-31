#include <fstream>
#include <vector>
#include <filesystem>
#include "clibr.update.dpr.hpp"
#include "../core/clibr.utils.hpp"
#include "../core/clibr.print.hpp"
#include "../../clibr.pch.hpp"

namespace clibr
{
    bool CommandUpdateDpr::execute(
        const std::string& dirName, const std::string& fileName, ICli* cli)
    {
        std::filesystem::path currentDir{ std::filesystem::current_path() / dirName };
        currentDir = std::filesystem::canonical(currentDir);
        std::vector<std::filesystem::directory_entry> files;

        for (const auto& entry : std::filesystem::directory_iterator(currentDir))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".dpr")
            {
                files.push_back(entry);
            }
        }

        std::string dprFilePath{ "" };
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

        intptr_t usesIndex{ -1 };
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
            Print::printAlert("Error: 'uses' clause not found in the DPR file.");
            return false;
        }

        intptr_t semicolonIndex{ -1 };
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
            Print::printAlert("Error: Semicolon not found after the 'uses' clause in the DPR file.");
            return false;
        }
        lines[semicolonIndex] = lines[semicolonIndex].replace(lines[semicolonIndex].find(';'), 1, ",");

        for (const std::string& unitName : cli->updates())
        {
            if (std::ranges::find(lines.begin(), lines.end(), unitName) != lines.end())
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
        Print::printUpdate("UPDATE", update.append(dirName)
            .append("/")
            .append(files[0].path().filename().string()), Utils::getSizeFile(dprFilePath));

        return true;
    }

    bool equalsIgnoreCase(const std::string& str1, const std::string& str2)
    {
        if (str1.size() != str2.size())
        {
            return false;
        }

        for (size_t i = 0; i < str1.size(); ++i)
        {
            if (std::tolower(str1[i]) != std::tolower(str2[i]))
            {
                return false;
            }
        }
        return true;
    }
}