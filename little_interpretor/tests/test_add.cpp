/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** test_add
*/


#include "gtest/gtest.h"
#include "Factory.hpp"

TEST(add, int16_int16)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int16, "2") + *Factory::createOperand(eOperandType::Int16, "3"));
    ASSERT_EQ("5", tmp->toString());
    ASSERT_EQ(eOperandType::Int16, tmp->getType());
}

TEST(add, int16_float)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int16, "2") + *Factory::createOperand(eOperandType::Float, "3"));
    ASSERT_EQ("5", tmp->toString());
    ASSERT_EQ(eOperandType::Float, tmp->getType());
}

TEST(add, bigdecimal_bigdecimal)
{
  IOperand *tmp = (*Factory::createOperand(eOperandType::BigDecimal, "8.41212421901094122921808643250787428301952214610088309300632724963328") + *Factory::createOperand(eOperandType::BigDecimal, "4.1212421901094122921808643250787428301952214610088309300632724963328"));
  ASSERT_EQ("12.533366409120353521071400404451878785039298236370086669921875", tmp->toString());
}

TEST(add, int8_overflow)
{
    try {
        IOperand *tmp = (*Factory::createOperand(eOperandType::Int8, "120") + *Factory::createOperand(eOperandType::Int8, "120"));
        FAIL() << "Expected Int8 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int8 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int8 overflow:";
    }
}

TEST(add, int8_underflow)
{
    try {
        IOperand *tmp = (*Factory::createOperand(eOperandType::Int8, "-120") + *Factory::createOperand(eOperandType::Int8, "-120"));
        FAIL() << "Expected Int8 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int8 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int8 overflow:";
    }
}

TEST(add, int16_overflow)
{
    try {
        IOperand *tmp = (*Factory::createOperand(eOperandType::Int16, "60000") + *Factory::createOperand(eOperandType::Int16, "60000"));
        FAIL() << "Expected Int16 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int16 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int16 overflow:";
    }
}

TEST(add, int16_undverflow)
{
    try {
        IOperand *tmp = (*Factory::createOperand(eOperandType::Int16, "-60000") + *Factory::createOperand(eOperandType::Int16, "-60000"));
        FAIL() << "Expected Int16 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int16 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int16 overflow:";
    }
}

TEST(add, int32_overflow)
{
    try {
        IOperand *tmp = (*Factory::createOperand(eOperandType::Int32, "2000000000") + *Factory::createOperand(eOperandType::Int32, "2000000000"));
        FAIL() << "Expected Int32 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int32 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int32 overflow:";
    }
}

TEST(add, int32_underflow)
{
    try {
        IOperand *tmp = (*Factory::createOperand(eOperandType::Int32, "-2000000000") + *Factory::createOperand(eOperandType::Int32, "-2000000000"));
        FAIL() << "Expected Int32 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int32 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int32 overflow:";
    }
}


