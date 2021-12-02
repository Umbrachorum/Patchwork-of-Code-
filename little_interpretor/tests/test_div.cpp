/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** test_div
*/


#include "gtest/gtest.h"
#include "Factory.hpp"


TEST(div, int8_int8)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int8, "2") / *Factory::createOperand(eOperandType::Int8, "3"));
    ASSERT_EQ("0", tmp->toString());
    ASSERT_EQ(eOperandType::Int8, tmp->getType());
}

TEST(div, int8_double)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int8, "2") / *Factory::createOperand(eOperandType::Double, "3"));
    ASSERT_EQ("0.666666666666667", tmp->toString());
    ASSERT_EQ(eOperandType::Double, tmp->getType());
}
