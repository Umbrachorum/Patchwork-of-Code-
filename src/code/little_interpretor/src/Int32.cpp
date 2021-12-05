//
// Created by gyann on 7/12/21.
//

#include <limits>
#include "Int32.hpp"
#include "Factory.hpp"
#include "Exceptions.hpp"

Operands::Int32::Int32(const std::string &value)
{
    this->type = eOperandType::Int32;
    this->value = value;
  clean_right_zeros(this->value);
    this->decimal = std::stol(value, nullptr);
    if (this->decimal < std::numeric_limits<int>::min() ||
        this->decimal > std::numeric_limits<int>::max())
        throw std::overflow_error("Int32 overflow !");
}

std::string Operands::Int32::toString() const
{
    return this->value;
}

eOperandType Operands::Int32::getType() const
{
    return this->type;
}

IOperand *Operands::Int32::operator+(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a + b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int32::operator-(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a - b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int32::operator*(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a * b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Int32::operator/(const IOperand &rhs) const
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

IOperand *Operands::Int32::operator%(const IOperand &rhs) const
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