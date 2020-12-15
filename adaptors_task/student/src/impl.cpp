#include "impl.h"
#include <vector>

#include <stack>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

bool isValid(const std::string& source) {
    if (source.empty())
        return true;

    std::stack<char> left_brackets;

    for (auto symbol : source) {
        for (auto bracket : brackets) {
            if (symbol == bracket.first)
                left_brackets.push(symbol);
            if (symbol == bracket.second) {
                if (left_brackets.empty())
                    return false;
                if (left_brackets.top() != bracket.first)
                    return false;
                left_brackets.pop();
            }
        }
    }

    if (!left_brackets.empty())
        return false;

    return true;
}
