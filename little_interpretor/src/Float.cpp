//
// Created by gyann on 7/12/21.
//

#include <limits>
#include "Float.hpp"
#include "Factory.hpp"
#include "Exceptions.hpp"

Operands::Float::Float(const std::string &value)
{
  this->type = eOperandType::Float;
    this->value = roundOperand(value, 7);
    double val = std::stod(this->value);
    clean_right_zeros(this->value);
  if ((val > 0 && val < std::numeric_limits<float>::min()) || (val < 0 && val > -std::numeric_limits<float>::min()))
      throw std::underflow_error("Float underflow !");
    if ( val > std::numeric_limits<float>::max())
      throw std::overflow_error("Float overflow !");
}

std::string Operands::Float::toString() const
{
  return this->value;
}

eOperandType Operands::Float::getType() const
{
  return this->type;
}

IOperand* Operands::Float::operator+(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  auto a = READ_PVAL(this, tpe);
  auto b = READ_VAL(rhs, tpe);
  auto c = a + b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::Float::operator-(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  auto a = READ_PVAL(this, tpe);
  auto b = READ_VAL(rhs, tpe);
  auto c = a - b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::Float::operator*(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  auto a = READ_PVAL(this, tpe);
  auto b = READ_VAL(rhs, tpe);
  auto c = a * b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::Float::operator/(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  auto a = READ_PVAL(this, tpe);
  auto b = READ_VAL(rhs, tpe);
  if (b == 0)
    throw ArithmeticException("null division !");
  auto c = a / b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::Float::operator%([[maybe_unused]] const IOperand &rhs) const
{
  throw ArithmeticException("Floating point modulo!");
}