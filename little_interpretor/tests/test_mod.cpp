/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** test_mod
*/


#include "gtest/gtest.h"
#include "Factory.hpp"

TEST(mod, int16_int8)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int16, "7") % *Factory::createOperand(eOperandType::Int8, "3"));
    ASSERT_EQ("1", tmp->toString());
    ASSERT_EQ(eOperandType::Int16, tmp->getType());
}