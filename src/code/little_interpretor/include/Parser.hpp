//
// Created by umbra on 12/07/2021.
//

#ifndef B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_PARSER_HPP
#define B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_PARSER_HPP

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <memory>
#include "Type.hpp"
#include "Exceptions.hpp"


class Parser {
public:
    Parser(std::istream &st): stream(st){};
    ~Parser() = default;
    void get_input();

    std::string get_cmd();
    eOperandType get_type() const;
    std::string get_data_num() const;
    std::string set_command(std::string);
    void clear_num();
    int index_register();
    bool eof();
private:
    void check_exit();
    eOperandType parse_type();
    int set_value(std::string &);
    std::vector<std::string> cpy;
    std::string data;
    std::istream &stream;
    std::string command;
    std::string value;
    eOperandType type;
};

#endif //B_SYN_400_BDX_4_1_ABSTRACTVM_QUENTIN1_VEDRENNE_PARSER_HPP
