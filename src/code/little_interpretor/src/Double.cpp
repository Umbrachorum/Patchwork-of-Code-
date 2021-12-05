//
// Created by gyann on 7/12/21.
//

#include "Double.hpp"
#include "Factory.hpp"
#include "Exceptions.hpp"

Operands::Double::Double(const std::string &value)
{
    this->type = eOperandType::Double;
    this->value = roundOperand(value, 15);
    this->decimal = std::stod(value);
    clean_right_zeros(this->value);

}

std::string Operands::Double::toString() const
{
    return this->value;
}

eOperandType Operands::Double::getType() const
{
    return this->type;
}

IOperand *Operands::Double::operator+(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a + b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Double::operator-(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a - b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *Operands::Double::operator*(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    auto c = a * b;
    auto fac = Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
    return fac;
}

IOperand *Operands::Double::operator/(const IOperand &rhs) const
{
    eOperandType tpe = GET_TYPE(this->getType(), rhs.getType());
    auto a = READ_PVAL(this, tpe);
    auto b = READ_VAL(rhs, tpe);
    if (b == 0)
        throw ArithmeticException("null division !");
    auto c = a / b;
    return Factory::createOperand(GET_TYPE(this->getType(), rhs.getType()),
            to_string_precise(c, tpe));
}

IOperand *
Operands::Double::operator%([[maybe_unused]] const IOperand &rhs) const
{
    throw ArithmeticException("Floating point modulo!");
}
