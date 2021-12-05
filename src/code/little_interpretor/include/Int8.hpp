//
// Created by gyann on 7/12/21.
//

#ifndef B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_INT8_HPP
#define B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_INT8_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <memory>
#include "IOperand.hpp"


namespace Operands {

class Int8 : public IOperand {
public:
  explicit Int8(const std::string &value);

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
  int8_t decimal;
};
}
#endif // B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_INT8_HPP
