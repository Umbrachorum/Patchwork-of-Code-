//
// Created by gyann on 7/12/21.
//

#ifndef B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_INT16_HPP
#define B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_INT16_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <memory>
#include "IOperand.hpp"

namespace Operands {
class Int16 : public IOperand {
public:
  explicit Int16(const std::string &value);

  std::string toString() const override;
  eOperandType getType() const override;
  IOperand* operator+(const IOperand &rhs) const override;
  IOperand* operator-(const IOperand &rhs) const override;
  IOperand* operator*(const IOperand &rhs) const override;
  IOperand* operator/(const IOperand &rhs) const override;
  IOperand* operator%(const IOperand &rhs) const override;

private:
  std::string value;
  eOperandType type;
  int16_t decimal;
};
}

#endif // B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_INT16_HPP
