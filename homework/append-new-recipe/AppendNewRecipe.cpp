#include "AppendNewRecipe.hpp"

std::ofstream recipes("recipes.txt", std::ios::out | std::ios::app);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::string result{};
    std::stringstream ss{};
    ss << "Skladniki:\n";
    auto items = FormatIngredients(ingredients, amount);
    for (auto const item : items) {
        ss << item << ",\n";
    }
    ss << "\nKroki:\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        ss << i + 1 << ") " << steps[i] << ".\n";
    }
    ss << "___________________________________\n";
    return ss;
}
bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    if (recipes.is_open()) {
        recipes << FormatRecipit(steps, ingredients, amount).str();
        recipes.close();
        return true;
    } else {
        return false;
    }
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
            row += " mililitrow";
            break;
        }
        }
        row += " " + x;
        ++itr;
        res.push_back(row);
    }
    return res;
}
