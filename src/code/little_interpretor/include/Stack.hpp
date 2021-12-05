//
// Created by croquette on 7/12/21.
//

#ifndef ABSTRACTVM_STACK_HPP
#define ABSTRACTVM_STACK_HPP

#include <vector>
#include <utility>
#include "Exceptions.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Int8.hpp"


class Stack
{
public:
    Stack();
    std::unique_ptr<IOperand> pop();
    void push(std::unique_ptr<IOperand> val);
    void push(IOperand *val);
    void clear() noexcept;
    bool empty() const noexcept;
    void dup();
    void swap();
    void dump() const noexcept;
    bool expect(IOperand &ref) const;
    void store(std::size_t v);
    void load(std::size_t v);
    void print() const;
    void add();
    void sub();
    void mul();
    void div();
    void mod();
private:
    std::vector<std::unique_ptr<IOperand>> stack_;
    std::array<std::unique_ptr<IOperand>, 16> registries_;
    std::shared_ptr<void(int)> overflow_handler_;

};
#endif //ABSTRACTVM_STACK_HPP
