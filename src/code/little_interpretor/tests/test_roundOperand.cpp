/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** test_roundOperand
*/


#include "gtest/gtest.h"
#include "Factory.hpp"


TEST(roundOperand, round_float)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Float, "2.8792871897289172891798271897219818729817892718972189729817289718927198729187298179827198271987298172891792871987289172981728971982719872189729817");
    ASSERT_EQ("2.8792871", tmp->toString());
}

TEST(roundOperand, round_another_float)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Float, "0.143");
    ASSERT_EQ("0.143", tmp->toString());
}

TEST(roundOperand, round_double)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Double, "2.8792871897289172891798271897219818729817892718972189729817289718927198729187298179827198271987298172891792871987289172981728971982719872189729817");
    ASSERT_EQ("2.879287189728917", tmp->toString());
}

TEST(roundOperand, round_bigdecimal)
{
    IOperand *tmp = Factory::createOperand(eOperandType::BigDecimal, "2.87928718972891728917982718972198187298178927189721897298172897189271987291872981798271982719872981728917928719872891729817289719827198721897298178792871897289172891798271897219818729817892718972189729817289718927198729187298179827198271987298172891792871987289172981728971982719872189729817");
    ASSERT_EQ("2.87928718972891728917982718972198187298178927189721897298172897189271987291872981798271982719872981728917928719872891729817289719827198721897298178792871897289172891798271897219818729817892718972189729", tmp->toString());
}

TEST(roundOperand, round_bigfloat)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Float, "1000000000000000.0");
    ASSERT_EQ("1000000000000000", tmp->toString());
}

TEST(roundOperand, round_smaldigit)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Float, "0.02310");
    ASSERT_EQ("0.0231", tmp->toString());
}


TEST(roundOperand, round_zero)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Float, "0.0");
    ASSERT_EQ("0", tmp->toString());
}

TEST(roundOperand, round_double_no_right_zero)
{
    std::string str("130000000.00000000000000000");
    ASSERT_EQ("130000000", roundOperand(str, 15));
}


TEST(roundOperand, round_double_truncate)
{
    std::string str("130000000.12345123451234512345");
    ASSERT_EQ("130000000.123451234512345", roundOperand(str, 15));
}