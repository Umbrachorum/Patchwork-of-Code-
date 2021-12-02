//
// Created by gyann on 7/14/21.
//

#ifndef ABSTRACTVM_ROUNDOPERAND_HPP
#define ABSTRACTVM_ROUNDOPERAND_HPP

#include <iomanip>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "IOperand.hpp"

std::string roundOperand(const std::string &value, size_t precision);
void clean_right_zeros(std::string &str);

template <typename T>
std::string to_string_precise(const T val, eOperandType type)
{
    std::ostringstream os;
    std::string str;
    os.precision(
            (type == eOperandType::Float) ? 7 :
            (type == eOperandType::Double) ? 15 :
            (type == eOperandType::BigDecimal) ? 200 : 1
            );
    os << std::fixed << val;
    str = os.str();
    return str;
}

#endif // ABSTRACTVM_ROUNDOPERAND_HPP
