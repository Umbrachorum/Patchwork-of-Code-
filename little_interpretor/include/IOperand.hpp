//
// Created by gyann on 7/12/21.
//

#ifndef B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_IOPERAND_HPP
#define B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_IOPERAND_HPP

#include "Type.hpp"
#include "Exceptions.hpp"
#include "roundOperand.hpp"

#define GET_TYPE(x, y)  ((x < y) ? y : x)
#define ST(x, t)           ((t < eOperandType::Float) ? x : static_cast<long double>(x))
#define READ_VAL(x, t)     ((x.getType() < eOperandType::Float) ? ST(std::stoi(x.toString()), t) : std::stold(x.toString()))
#define READ_PVAL(x, t)    ((x->getType() < eOperandType::Float) ? ST(std::stoi(x->toString()), t) : std::stold(x->toString()))

std::string roundOperand(std::string &value, eOperandType type);

class IOperand
{
public:
  virtual std::string toString() const = 0;
  virtual eOperandType getType() const = 0;
  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {};
};

#endif // B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_IOPERAND_HPP
