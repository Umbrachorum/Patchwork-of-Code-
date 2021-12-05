//
// Created by gyann on 7/12/21.
//

#ifndef B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_FLOAT_HPP
#define B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_FLOAT_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <memory>
#include "IOperand.hpp"

namespace Operands {
class Float : public IOperand {
public:
  explicit Float(const std::string &value);

  std::string toString() const override;
  eOperandType getType() const override;
  IOperand* operator+(const IOperand &rhs) const override;
  IOperand* operator-(const IOperand &rhs) const override;
  IOperand* operator*(const IOperand &rhs) const override;
  IOperand* operator/(const IOperand &rhs) const override;
  IOperand* operator%(const IOperand &rhs) const override;

private:
  eOperandType type;
  std::string value;
  long double decimal;
  int8_t int8;
};
}

#endif // B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_FLOAT_HPP
