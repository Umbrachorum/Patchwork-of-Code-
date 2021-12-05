//
// Created by gyann on 7/12/21.
//

#include "Factory.hpp"

IOperand* Factory::createOperand(eOperandType type, const std::string &value)
{
  static constexpr PtrFunc array[6] = { &FacCtor<Operands::Int8>, &FacCtor<Operands::Int16>, &FacCtor<Operands::Int32>,
      &FacCtor<Operands::Float>, &FacCtor<Operands::Double>, &FacCtor<Operands::BigDecimal> };
  return array[type](value);
}

IOperand *Factory::dupOperand(IOperand &src)
{
  return createOperand(src.getType(), src.toString());
}
