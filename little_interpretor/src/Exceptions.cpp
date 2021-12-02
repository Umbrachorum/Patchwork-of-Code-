//
// Created by croquette on 7/12/21.
//

#include <utility>
#include "Exceptions.hpp"


Exceptions::Exceptions(std::string message, std::string title)
: msg_(std::move(message)), type_(std::move(title))
{
}

char const *Exceptions::msg() const noexcept
{
    return msg_.c_str();
}

char const *Exceptions::type() const noexcept
{
    return type_.c_str();
}

const char *Exceptions::what() const noexcept
{
    return msg();
}

StackException::StackException(std::string message)
: Exceptions(std::move(message), "Stack Exception")
{

}

ArithmeticException::ArithmeticException(std::string message)
: Exceptions(std::move(message), "Arithmetic Exception")
{

}

CoreException::CoreException(std::string message)
        : Exceptions(std::move(message), "Core Exception")
{

}

ParserException::ParserException(std::string message)
        : Exceptions(std::move(message), "Parser Exception")
{

}