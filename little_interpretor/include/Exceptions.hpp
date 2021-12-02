//
// Created by croquette on 7/12/21.
//

#ifndef ABSTRACTVM_EXCEPTIONS_HPP
#define ABSTRACTVM_EXCEPTIONS_HPP

#include <stdexcept>

class Exceptions : public std::exception
{
public:
    Exceptions(std::string message, std::string title);
    ~Exceptions() noexcept override = default;
    char const *msg() const noexcept;
    char const *type() const noexcept;

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

private:
    std::string msg_;
    std::string type_;
};

class StackException : public Exceptions
{
public:
    StackException(std::string message);
};

class ArithmeticException : public Exceptions
{
public:
    ArithmeticException(std::string message);
};

class CoreException : public Exceptions
{
public:
  CoreException(std::string message);
};

class ParserException : public Exceptions
{
public:
    ParserException(std::string message);
};

#endif //ABSTRACTVM_EXCEPTIONS_HPP
