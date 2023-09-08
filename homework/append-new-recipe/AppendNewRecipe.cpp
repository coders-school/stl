#include "AppendNewRecipe.hpp"

std::ofstream recipes("recipes.txt");

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> res{};
    auto itr = amount.begin();
    for (auto x : ingredients) {
        std::stringstream ss{};
        std::string row{};
        ss << itr->first;
        row = ss.str();
        switch (itr->second) {
        case 'g': {
            row += " gram";
            break;
        }
        case 's': {
            row += " szklanka(i)";
            break;
        }
        case 'm': {
            row += "ml";
            break;
        }
        }
        ++itr;
        res.push_back(row);
    }
    for (auto x : res) {
        std::cout << x << "\n";
    }
}
/*
20 gram cukru,
1 szklanka(i) mąki,
40ml rumu,
*/