/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** test_sub
*/


#include "gtest/gtest.h"
#include "Factory.hpp"

TEST(sub, float_float)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Float, "2") - *Factory::createOperand(eOperandType::Float, "3"));
    ASSERT_EQ("-1", tmp->toString());
    ASSERT_EQ(eOperandType::Float, tmp->getType());
}

TEST(sub, float_double)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Float, "2") - *Factory::createOperand(eOperandType::Double, "3"));
    ASSERT_EQ("-1", tmp->toString());
    ASSERT_EQ(eOperandType::Double, tmp->getType());
}