//
// Created by croquette on 7/12/21.
//

#include <fstream>
#include "gtest/gtest.h"
#include "Parser.hpp"

TEST(Parser, testing_cmd_error)
{
    std::ifstream fd("example/example1.txt");
    Parser p(fd);
    eOperandType t;
    t = eOperandType::Int8;
    ASSERT_EQ(eOperandType::Int8,  t);
}

TEST(Parser, testing_cmd_error_bis) {
    std::ifstream fd("example/example1.txt");
    Parser p(fd);
    std::string test = "TPTP";
    try {
        p.set_command(test);
        FAIL() << "Wrong cmd";
    } catch (ParserException const &e) {
        ASSERT_EQ(0, strcmp("Wrong command", e.msg()));
        ASSERT_EQ(0, strcmp("Parser Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception fail with handler switch command";
    }
}

TEST(Parser, testing_command) {
    std::ifstream fd("example/example1.txt");
    Parser p(fd);
    std::string test = "push int8(32)";
    std::string stock;
    stock = p.set_command(test);
    ASSERT_EQ(0, strcmp("push", stock.c_str()));
}

TEST(Parser, testing_command_in_const) {
    std::ifstream fd("example/example1.txt");
    Parser p(fd);
    std::string test = ";;";
    std::string stock;
    stock = p.set_command(test);
    ASSERT_EQ(0, strcmp("end", stock.c_str()));
}

TEST(Parser, wrong_type_with_loop_err) {
    std::ifstream fd("example/example1.txt");
    Parser p(fd);
    eOperandType t;
    std::string test = "push sqdqdae(32)";
    std::string stock;
    try {
        p.get_input();
        t = p.get_type();
    } catch (ParserException const &e) {
        ASSERT_EQ(0, strcmp("Wrong command", e.msg()));
        ASSERT_EQ(0, strcmp("Parser Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception fail with handler switch command";
    }
}

TEST(Parser, wrong_type_with_loop) {
    std::ifstream fd("example/for_test_one.txt");
    Parser p(fd);
    eOperandType type_copy;
    p.get_input();
    type_copy = p.get_type();
    ASSERT_EQ(eOperandType::Int8, type_copy);
}

TEST(Parser, value_with_loop) {
    std::ifstream fd("example/for_test_one.txt");
    Parser p(fd);
    std::string value_copy;
    p.get_input();
    value_copy = p.get_data_num();
    ASSERT_EQ(0, strcmp(value_copy.c_str(), "33"));
}

TEST(Parser, value_with_loop_without_end) {
    std::ifstream fd("example/for_test_two.txt");
    Parser p(fd);
    std::string value_copy;
    try {
        p.get_input();
        value_copy = p.get_data_num();
    } catch (ParserException const &e) {
        ASSERT_EQ(0, strcmp("Not closing ) for value", e.msg()));
        ASSERT_EQ(0, strcmp("Parser Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception fail with handler switch command";
    }
}

TEST(Parser, value_with_float_in_int) {
    std::ifstream fd("example/for_test_tree.txt");
    Parser p(fd);
    std::string value_copy;
    try {
        p.get_input();
        value_copy = p.get_data_num();
    } catch (ParserException const &e) {
        ASSERT_EQ(0, strcmp("Can't set float in Int", e.msg()));
        ASSERT_EQ(0, strcmp("Parser Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception fail with handler switch command";
    }
}

TEST(Parser, value_without_begin_param) {
    std::ifstream fd("example/for_test_four.txt");
    Parser p(fd);
    std::string value_copy;
    try {
        p.get_input();
        value_copy = p.get_data_num();
    } catch (ParserException const &e) {
        ASSERT_EQ(0, strcmp("Wrong command", e.msg()));
        ASSERT_EQ(0, strcmp("Parser Exception", e.type()));
    } catch (...) {
        FAIL() << "Expected exception fail with handler switch command";
    }
}

TEST(Parser, value_stdin_exit)
{
    Parser p(std::cin);
    std::string value_copy;
    value_copy = p.set_command(";;");
    ASSERT_EQ(0, strcmp("end", value_copy.c_str()));
}

TEST(Parser, value_read_exit)
{
    std::ifstream fd("example/for_exit_test.txt");
    Parser p(fd);
    std::string value_copy;
    p.get_input();
    value_copy = p.get_cmd();
    ASSERT_EQ(0, strcmp("exit", value_copy.c_str()));
}

TEST(Parser, comment_line)
{
    Parser p(std::cin);
    std::string value_copy;
    value_copy = p.set_command(";hello");
    ASSERT_EQ(0, strcmp("", value_copy.c_str()));
}