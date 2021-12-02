//
// Created by croquette on 7/13/21.
//

#include <cfenv>
#include <csignal>
#include "Stack.hpp"



std::unique_ptr<IOperand> Stack::pop()
{
    if (stack_.empty())
        throw StackException("stack empty!");
    std::unique_ptr<IOperand> val(stack_.back().release());
    stack_.pop_back();
    return val;
}


void Stack::push(std::unique_ptr<IOperand> val)
{
    stack_.emplace_back(std::move(val));
}


void Stack::clear() noexcept
{
    stack_.clear();
}


bool Stack::empty() const noexcept
{
    return stack_.empty();
}


void Stack::dup()
{
    if (empty())
        throw StackException("stack empty!");
    std::unique_ptr<IOperand> copy(Factory::dupOperand(*stack_.back().get()));
    stack_.emplace_back(std::move(copy));
}


void Stack::swap()
{
    if (stack_.size() < 2)
        throw StackException("need at least 2 values!");
    std::iter_swap(stack_.end() - 1, stack_.end() - 2);
}


void Stack::dump() const noexcept
{
    auto it = stack_.end();

    while (it != stack_.begin()) {
        --it;
        std::cout << it->get()->toString() << std::endl;
    }
}


bool Stack::expect(IOperand &ref) const
{
    if (empty())
        throw StackException("stack empty!");
    return (stack_.back().get()->toString() == ref.toString());
}

void Stack::store(std::size_t v)
{
    if (empty())
        throw StackException("stack empty!");
    if (v > 15)
        throw StackException("registry index out of range!");
    registries_[v] = pop();
}

void Stack::load(std::size_t v)
{
    if (v > 15)
        throw StackException("registry index out of range!");
    if (!registries_[v].get())
        throw StackException("registry uninitialized!");
    std::unique_ptr<IOperand> copy(Factory::dupOperand(*registries_[v].get()));
    push(std::move(copy));
}

void Stack::print() const
{
    if (empty())
        throw StackException("stack empty!");
    if (!dynamic_cast<Operands::Int8 *>(stack_.back().get()))
        throw StackException("not a 8 bit integer!");
    std::cout << char(std::stoi(stack_.back().get()->toString())) << std::endl;
}

void Stack::push(IOperand *val)
{
    if (!val)
        throw StackException("tried to push null object!");
    stack_.emplace_back(std::unique_ptr<IOperand>(val));
}

void Stack::add()
{
    if (stack_.size() < 2)
        throw StackException("need at least 2 values!");
    IOperand *a = pop().release();
    IOperand *b = pop().release();
    push(std::unique_ptr<IOperand>(*b + *a));
    delete a;
    delete b;
}

void Stack::sub()
{
    if (stack_.size() < 2)
        throw StackException("need at least 2 values!");
    IOperand *a = pop().release();
    IOperand *b = pop().release();
    push(std::unique_ptr<IOperand>(*b - *a));
    delete a;
    delete b;
}

void Stack::mul()
{
    if (stack_.size() < 2)
        throw StackException("need at least 2 values!");
    IOperand *a = pop().release();
    IOperand *b = pop().release();
    push(std::unique_ptr<IOperand>(*b * *a));
    delete a;
    delete b;
}

void Stack::div()
{
    if (stack_.size() < 2)
        throw StackException("need at least 2 values!");
    IOperand *a = pop().release();
    IOperand *b = pop().release();
    push(std::unique_ptr<IOperand>(*b / *a));
    delete a;
    delete b;
}

void Stack::mod()
{
    if (stack_.size() < 2)
        throw StackException("need at least 2 values!");
    IOperand *a = pop().release();
    IOperand *b = pop().release();
    push(std::unique_ptr<IOperand>(*b % *a));
    delete a;
    delete b;
}

Stack::Stack() : overflow_handler_(std::signal(SIGFPE,
        []([[maybe_unused]]int signum) {
            throw std::overflow_error("Double overflow !");
        }), [](__sighandler_t f) { signal(SIGFPE, f); })
{
    feenableexcept(FE_OVERFLOW | FE_UNDERFLOW);
}