//
// Created by croquette on 7/12/21.
//

#include "gtest/gtest.h"
#include "Stack.hpp"
#include "Factory.hpp"


TEST(stack, pop_empty_stack)
{
    Stack stack;
    try {
        stack.pop();
        FAIL() << "Expected exception empty stack";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("stack empty!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception empty stack";
    }
}

TEST(stack, simple_push_stack)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "8"));
    stack.push(Factory::createOperand(Int32, "10"));
    ASSERT_EQ(10, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(8, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
}

TEST(stack, clear_empty_stack)
{
    Stack stack;
    stack.clear();
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, clear_stack)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "8"));
    stack.push(Factory::createOperand(Int32, "10"));
    ASSERT_EQ(false, stack.empty());
    stack.pop();
    ASSERT_EQ(false, stack.empty());
    stack.pop();
    ASSERT_EQ(false, stack.empty());
    stack.pop();
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, dup_empty)
{
    Stack stack;
    try {
        stack.dup();
        FAIL() << "Expected exception empty stack";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("stack empty!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception empty stack";
    }
}

TEST(stack, dup_basic)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "8"));
    stack.dup();
    ASSERT_EQ(8, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(8, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
}

TEST(stack, dup_advanced)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "2"));
    stack.dup();
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, swap_missing_value)
{
    Stack stack;
    try {
        stack.swap();
        FAIL() << "Expected exception need at least 2 values";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("need at least 2 values!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception empty stack";
    }
}

TEST(stack, swap)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "8"));
    stack.swap();
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(8, std::stoi(stack.pop()->toString()));
}

TEST(stack, swap_big)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "1"));
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "3"));
    stack.push(Factory::createOperand(Int32, "4"));
    stack.push(Factory::createOperand(Int32, "5"));
    stack.swap();
    ASSERT_EQ(4, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(5, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(3, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(1, std::stoi(stack.pop()->toString()));
}


TEST(stack, dump)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "1"));
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "9"));
    stack.push(Factory::createOperand(Int32, "-32"));
    stack.push(Factory::createOperand(Int32, "4"));
    stack.push(Factory::createOperand(Int32, "87"));
    stack.dump();
}


TEST(stack, expect_empty)
{
    Stack stack;
    std::unique_ptr<IOperand> a(Factory::createOperand(Int32, "1"));
    try {
        stack.expect(*a.get());
        FAIL() << "Expected exception empty stack";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("stack empty!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception empty stack";
    }
}

TEST(stack, expect_true)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "10"));
    std::unique_ptr<IOperand> a(Factory::createOperand(Int32, "10"));
    ASSERT_EQ(true, stack.expect(*a));
}

TEST(stack, expect_false)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "11"));
    std::unique_ptr<IOperand> a(Factory::createOperand(Int32, "10"));
    ASSERT_EQ(false, stack.expect(*a));
}

TEST(stack, store_empty)
{
    Stack stack;
    try {
        stack.store(5);
        FAIL() << "Expected exception empty stack";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("stack empty!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception empty stack";
    }
}

TEST(stack, store_big_index_registry)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "4"));
    try {
        stack.store(205);
        FAIL() << "Expected exception registry index out of range";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("registry index out of range!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception registry index out of range";
    }
}

TEST(stack, store_registry)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "2"));
    stack.push(Factory::createOperand(Int32, "4"));
    stack.store(3);
    ASSERT_EQ(2, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, load_index_out_of_range)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "4"));
    try {
        stack.load(205);
        FAIL() << "Expected exception registry index out of range";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("registry index out of range!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception registry index out of range";
    }
}

TEST(stack, load_registry_uninitialized)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "4"));
    try {
        stack.load(5);
        FAIL() << "Expected exception registry uninitialized";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("registry uninitialized!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception registry uninitialized";
    }
}

TEST(stack, load_basic)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "4"));
    stack.store(3);
    ASSERT_EQ(true, stack.empty());
    stack.load(3);
    stack.load(3);
    ASSERT_EQ(false, stack.empty());
    ASSERT_EQ(4, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(4, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, print_ascii_empty)
{
    Stack stack;
    try {
        stack.print();
        FAIL() << "Expected exception empty stack";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("stack empty!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception empty stack";
    }
}


TEST(stack, print_ascii_wrong_format)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "81"));
    try {
        stack.print();
        FAIL() << "Expected exception not a 8 bit integer";
    } catch (StackException const &e) {
        ASSERT_EQ(0, strcmp("not a 8 bit integer!", e.msg()));
        ASSERT_EQ(0, strcmp("Stack Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception not a 8 bit integer";
    }
}

TEST(stack, print_ascii)
{
    Stack stack;
    stack.push(Factory::createOperand(Int8, "81"));
    stack.print();
}

TEST(stack, add_simple)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "174"));
    stack.push(Factory::createOperand(Int32, "9342"));
    stack.add();
    ASSERT_EQ(9516, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, add_float_int)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "9342"));
    stack.push(Factory::createOperand(Float, "0.143"));
    stack.add();
    ASSERT_EQ("9342.143", stack.pop()->toString());
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, add_double_overflow)
{
    Stack stack;
    try {
        stack.push(Factory::createOperand(Double,
                "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0"));
        stack.push(Factory::createOperand(Double,
                "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0"));
        stack.add();
        FAIL() << "Expected Double overflow !";
    } catch (std::overflow_error &e) {
        ASSERT_EQ(0, std::strcmp("Double overflow !", e.what()));
    } catch (...) {
        FAIL() << "Expected Double overflow !";
    }
}

TEST(stack, sub_simple)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "134"));
    stack.push(Factory::createOperand(Int32, "9342"));
    stack.sub();
    ASSERT_EQ(-9208, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, mul_simple)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "174"));
    stack.push(Factory::createOperand(Int32, "100"));
    stack.mul();
    ASSERT_EQ(17400, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, div_simple)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "4000"));
    stack.push(Factory::createOperand(Int32, "8"));
    stack.div();
    ASSERT_EQ(500, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}

TEST(stack, mod_simple)
{
    Stack stack;
    stack.push(Factory::createOperand(Int32, "175"));
    stack.push(Factory::createOperand(Int32, "2"));
    stack.mod();
    ASSERT_EQ(1, std::stoi(stack.pop()->toString()));
    ASSERT_EQ(true, stack.empty());
}