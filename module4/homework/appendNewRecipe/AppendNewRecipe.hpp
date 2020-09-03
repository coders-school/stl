#pragma once

#include <deque>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/*struct VolumeClass
{
    enum class Volume : char {
        g,
        m,
        s
    };
};

const char* enumToString (VolumeClass::Volume e)
{
    const std::map<VolumeClass::Volume,const char*> volume {
        { VolumeClass::Volume::g, "gram" },
        { VolumeClass::Volume::m, "mililitry" },
        { VolumeClass::Volume::s, "szklanki" }
    };
    auto it = volume.find(e);
    return it == volume.end() ? "Out of range" : it->second;
};*/

enum class Volume {
    g,
    m,
    s
};

bool AppendNewRecipeconst(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);

std::string convertEnumToString(char c);