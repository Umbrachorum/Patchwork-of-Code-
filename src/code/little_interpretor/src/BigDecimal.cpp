//
// Created by gyann on 7/12/21.
//

#include "BigDecimal.hpp"
#include "Factory.hpp"
#include "Exceptions.hpp"

Operands::BigDecimal::BigDecimal(const std::string &value)
{
  this->type = eOperandType::BigDecimal;
  this->value = roundOperand(value, 200);
  this->decimal = std::stold(this->value, 0);
    clean_right_zeros(this->value);
}

std::string Operands::BigDecimal::toString() const
{
  return this->value;
}

eOperandType Operands::BigDecimal::getType() const
{
  return this->type;
}

IOperand* Operands::BigDecimal::operator+(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  long double a = std::stold(this->value);
  long double b = std::stold(rhs.toString());
  long double c = a + b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::BigDecimal::operator-(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  long double a = std::stold(this->value);
  long double b = std::stold(rhs.toString());
  long double c = a - b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::BigDecimal::operator*(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  long double a = std::stold(this->value);
  long double b = std::stold(rhs.toString());
  long double c = a * b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::BigDecimal::operator/(const IOperand &rhs) const
{
  eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
  long double a = std::stold(this->value);
  long double b = std::stold(rhs.toString());
  if (b == 0)
    throw ArithmeticException("null division !");
  long double c = a / b;
  return Factory::createOperand(
      GET_TYPE(this->getType(), rhs.getType()),
      to_string_precise(c, tpe));
}

IOperand* Operands::BigDecimal::operator%([[maybe_unused]] const IOperand &rhs) const
{
  throw ArithmeticException("Floating point modulo!");
}