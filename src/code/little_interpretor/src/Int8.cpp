//
// Created by gyann on 7/12/21.
//

#include <limits>
#include "Int8.hpp"
#include <Factory.hpp>
#include "Exceptions.hpp"

Operands::Int8::Int8(const std::string &value)
{
    int tmp = std::stoi(value);
    if (tmp < std::numeric_limits<int8_t>::min() ||
        tmp > std::numeric_limits<int8_t>::max())
        throw std::overflow_error("Int8 overflow !");
    this->type = eOperandType::Int8;
    this->value = value;
  clean_right_zeros(this->value);
  this->decimal = tmp;
}

std::string Operands::Int8::toString() const
{
    return this->value;
}

eOperandType Operands::Int8::getType() const
{
    return this->type;
}

IOperand *Operands::Int8::operator+(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a + b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int8::operator-(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a - b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int8::operator*(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a * b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int8::operator/(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    double a = READ_PVAL(this, tpe);
    double b = READ_VAL(rhs, tpe);
    if (b == 0)
        throw ArithmeticException("null division !");
    double c;
    if (tpe < eOperandType::Float)
        c = static_cast<int>(a) / static_cast<int>(b);
    else
        c = a / b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int8::operator%(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = static_cast<int>(READ_PVAL(this, tpe));
    auto b = static_cast<int>(READ_VAL(rhs, tpe));
    if (b == 0)
        throw ArithmeticException("null modulo !");
    auto c = a % b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}
