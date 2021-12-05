/*
** EPITECH PROJECT, 2020
** abstractVM
** File description:
** test_mul
*/


#include "gtest/gtest.h"
#include "Stack.hpp"
#include "Factory.hpp"

TEST(mul, int32_int32)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int32, "2") * *Factory::createOperand(eOperandType::Int32, "3"));
    ASSERT_EQ("6", tmp->toString());
    ASSERT_EQ(eOperandType::Int32, tmp->getType());
}

TEST(mul, int32_bigdecimal)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Int32, "2") * *Factory::createOperand(eOperandType::BigDecimal, "3"));
    ASSERT_EQ("6", tmp->toString());
    ASSERT_EQ(eOperandType::BigDecimal, tmp->getType());
}

TEST(mul, double_double)
{
    IOperand *tmp = (*Factory::createOperand(eOperandType::Double, "16") * *Factory::createOperand(eOperandType::Double, "0.25"));
    ASSERT_EQ("4", tmp->toString());
    ASSERT_EQ(eOperandType::Double, tmp->getType());
}

TEST(mul, int32_overflow)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Int32, "13");
    IOperand *fact = Factory::createOperand(eOperandType::Int8, "10");

    try {
        for (int i = 0; i < 1000; ++i) {
            tmp = *tmp * *fact;
        }
        FAIL() << "Expected Int32 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int32 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int32 overflow:";
    }
}

TEST(mul, int16_overflow)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Int16, "13");
    IOperand *fact = Factory::createOperand(eOperandType::Int8, "10");

    try {
        for (int i = 0; i < 1000; ++i) {
            tmp = *tmp * *fact;
        }
        FAIL() << "Expected Int16 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int16 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int16 overflow:";
    }
}

TEST(mul, int8_overflow)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Int8, "13");
    IOperand *fact = Factory::createOperand(eOperandType::Int8, "10");

    try {
        for (int i = 0; i < 1000; ++i) {
            tmp = *tmp * *fact;
        }
        FAIL() << "Expected Int8 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Int8 overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int8 overflow:";
    }
}

TEST(mul, float_overflow)
{
    IOperand *tmp = Factory::createOperand(eOperandType::Float, "13000");
    IOperand *fact = Factory::createOperand(eOperandType::Float, "10000");

    try {
        for (int i = 0; i < 1000; ++i) {
            tmp = *tmp * *fact;
        }
        FAIL() << "Expected Int32 overflow:";
    } catch (std::overflow_error const &e) {
        ASSERT_EQ(0, std::strcmp("Float overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Int32 overflow:";
    }
}

/*

TEST(mul, double_overflow)
{
    Stack stack;
    IOperand *tmp = Factory::createOperand(eOperandType::Double, "13000");
    IOperand *fact = Factory::createOperand(eOperandType::Double, "10000");
    try {
        for (int i = 0; i < 10000; ++i) {
            tmp = *tmp * *fact;
        }
        FAIL() << "Expected Double overflow:";
    } catch (std::overflow_error &e) {
        ASSERT_EQ(0, std::strcmp("Double overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Double overflow:h";
    }
}*/