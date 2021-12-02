//
// Created by gyann on 7/14/21.
//

#include <sstream>
#include "roundOperand.hpp"

void clean_right_zeros(std::string &str)
{
    if (str.find('.', 0) == std::string::npos)
        return;
    auto it = str.rbegin();
    while (it != str.rend()) {
        if (*it == '0')
            str.pop_back();
        else {
            if (*it == '.')
                str.pop_back();
            return;
        }
        ++it;
    }
}

std::string roundOperand(const std::string &value, size_t precision)
{
    size_t it;
    if ((it = value.find('.', 0)) != 0) {
        std::string tmp(value);
        if (value.size() - it > precision + 1)
            tmp.erase(it + precision + 1, std::string::npos);
        clean_right_zeros(tmp);
        return tmp;
    }
    return value;
}
