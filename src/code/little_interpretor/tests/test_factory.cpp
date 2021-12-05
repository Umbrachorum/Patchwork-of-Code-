//
// Created by gyann on 7/14/21.
//

#include "gtest/gtest.h"
#include "Factory.hpp"

TEST(factory, create_int8_underflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Int8, "-140");
  } catch (std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Int8 overflow !", e.what()));
  }
}

TEST(factory, create_int16_underflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Int16, "-4000");
  } catch (std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Int16 overflow !", e.what()));
  }
}

TEST(factory, create_int32_underflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Int32, "-2147483648111");
  } catch(std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Int32 overflow !", e.what()));
  }
}

TEST(factory, create_float_underflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Float, "-2147483648214748364821474836482147483648,21474836482147483648");
  } catch(std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Float underflow !", e.what()));
  }
}

TEST(factory, create_double_underflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Float, "-214748364821474836482147483648214748364821474836482147483648214748364821474836482147483648214748364821474836482147483648,214748364821474836482147483648214748364821474836482147483648");
  } catch(std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Double underflow !", e.what()));
  }
}

TEST(factory, create_int8_overflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Int8, "128");
  } catch (std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Int8 overflow !", e.what()));
  }
}

TEST(factory, create_int16_overflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Int16, "4000");
  } catch (std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Int16 overflow !", e.what()));
  }
}

TEST(factory, create_int32_overflow)
{
  try {
  IOperand *tmp = Factory::createOperand(Int32, "2147483648");
  FAIL() << "Expected exception Int32 overflow";
  } catch(std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Int32 overflow !", e.what()));
  }
}

TEST(factory, create_float_overflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Float, "2147483648214748364821474836482147483648,21474836482147483648");
  } catch(std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Float overflow !", e.what()));
  }
}

TEST(factory, create_double_overflow)
{
  try {
    IOperand *tmp = Factory::createOperand(Float, "214748364821474836482147483648214748364821474836482147483648214748364821474836482147483648214748364821474836482147483648,214748364821474836482147483648214748364821474836482147483648");
  } catch(std::overflow_error &e)
  {
    ASSERT_EQ(0, strcmp("Double overflow !", e.what()));
  }
}


TEST(factory, create_int8)
{
  IOperand *tmp = Factory::createOperand(Int8, "0");
  ASSERT_EQ(eOperandType::Int8, tmp->getType());
}

TEST(factory, create_int16)
{
  IOperand *tmp = Factory::createOperand(Int16, "0");
  ASSERT_EQ(eOperandType::Int16, tmp->getType());
}

TEST(factory, create_int32)
{
  IOperand *tmp = Factory::createOperand(Int32, "0");
  ASSERT_EQ(eOperandType::Int32, tmp->getType());
}

TEST(factory, create_float)
{
  IOperand *tmp = Factory::createOperand(Float, "0.0");
  ASSERT_EQ(eOperandType::Float, tmp->getType());
}

TEST(factory, create_double)
{
  IOperand *tmp = Factory::createOperand(Double, "0.0");
  ASSERT_EQ(eOperandType::Double, tmp->getType());
}

TEST(factory, create_bigdecimal)
{
  IOperand *tmp = Factory::createOperand(BigDecimal, "0.0");
  ASSERT_EQ(eOperandType::BigDecimal, tmp->getType());
}

