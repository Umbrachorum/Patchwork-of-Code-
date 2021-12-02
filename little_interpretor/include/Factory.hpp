//
// Created by gyann on 7/12/21.
//

#ifndef B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_FACTORY_HPP
#define B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_FACTORY_HPP

#include "Int16.hpp"
#include "Int8.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "BigDecimal.hpp"
#include <memory>

typedef IOperand* (*PtrFunc)(const std::string& value);

template <class T>
IOperand* FacCtor(const std::string &value)
{
  return (new T(value));
}

class Factory
{
public:
  static IOperand* createOperand(eOperandType type, const std::string& value);
  static IOperand* dupOperand(IOperand &src);

};

#endif // B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_FACTORY_HPP
