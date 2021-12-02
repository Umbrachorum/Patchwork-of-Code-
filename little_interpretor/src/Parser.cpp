//
// Created by umbra on 12/07/2021.
//

#include <fstream>
#include "Parser.hpp"

template<typename T>
std::vector<T> split(std::string &str, std::string &delim, std::vector<T> vec) {
    char *cpy;
    std::string dup;
    dup = str;
    cpy = std::strtok(const_cast<char *>(dup.c_str()), delim.c_str());
    while (cpy) {
        vec.push_back(cpy);
        cpy = std::strtok(nullptr, delim.c_str());
    }
    free(cpy);
    return vec;
}

std::string Parser::set_command(std::string string) {
    int i = 0;
    std::string cmd_separator = " ";
    char cmd[16][7] = {"pop", "dump", "clear", "swap", "dup", "assert", "add", "sub", "mul", "div", "mod", "load",
                       "store", "print", "exit", "push"};
    if ((string[0] == ';' && string[1] && string[1] != ';') || string.empty())
        return "";
    this->cpy = split(string, cmd_separator, this->cpy);
    while (i < 16) {
        if (!this->cpy.empty()) {
            if (this->cpy[0] == ";;")
                return "end";
            if (this->cpy[0] == cmd[i]) {
                return cmd[i];
            }
        }
        i++;
    }
    if(eof())
        return "end";
    throw ParserException("Wrong command");
}

std::string extract_num(std::string string) {
    std::string num;
    int i = 0;
    int x = 0;
    while (string[i]) {
        if (string[i] == '(') {
            i++;
            if((string.back()) != ')' && (string.back()) != ';')
                throw ParserException("Not closing ) for value");
            while (string[i] != ')' && string[i] != '\n' && string[i] != '\0') {
                num.push_back(string[i]);
                x++;
                i++;
            }
        }
        i++;
    }
    return num;
}

std::string cut_string(std::string string, char c) {
    std::size_t i = 0;
    std::string tmp;
    while (string[i] != c && string[i]) {
        tmp.push_back(string[i]);
        i++;
    }
    tmp.push_back(string[i]);
    if (i == strlen(string.c_str()) || i == 0) {
        tmp.clear();
        return tmp;
    }
    return tmp;
}

int Parser::set_value(std::string &value) {
    std::string tmp;
    if (this->cpy.size() < 2)
        return 84;
    std::string my_cpy = cut_string(this->cpy[1], '(');
    if (!my_cpy.empty() && value == my_cpy) {
        tmp = extract_num(this->cpy[1]);
        if (!tmp.empty()) {
            this->data = tmp;
            return 0;
        }
    }
    return 84;
}

eOperandType Parser::parse_type() {
    std::string tmp = "int8(";
    if (set_value(tmp) != 84) {
        return Int8;
    }
    tmp = "int16(";
    if (set_value(tmp) != 84) {
        return Int16;
    }
    tmp = "int32(";
    if (set_value(tmp) != 84) {
        return Int32;
    }
    tmp = "float(";
    if (set_value(tmp) != 84) {
        return Float;
    }
    tmp = "double(";
    if (set_value(tmp) != 84) {
        return Double;
    }
    tmp = "bigdecimal(";
    if (set_value(tmp) != 84) {
        return BigDecimal;
    } else
        return BigDecimal;
}

std::string Parser::get_data_num() const {
    return this->data;
}

void Parser::clear_num() {
    this->cpy.clear();
    this->data.clear();
    this->command.clear();
    this->value.clear();
}

int Parser::index_register() {
    if (this->cpy[0] == "load" || this->cpy[0] == "store") {
        if (this->cpy[1].empty())
            throw ParserException("Missing Value register");
        return std::stoi(this->cpy[1]);
    }
    return -1;
}

eOperandType Parser::get_type() const {
    return this->type;
}

void Parser::check_exit()
{
    if(&this->stream != &std::cin) {
        if(this->stream.eof())
            throw ParserException("Missing Exit");
    }
}

void Parser::get_input() {
    std::string buffer;
    std::getline(this->stream, buffer);
    this->command = set_command(buffer);
    check_exit();
    if (command == "end" && &stream == &std::cin) {
        this->command = "exit";
    }
    if (!this->cpy.empty() && !this->command.empty()) {
        this->type = parse_type();
        if(this->type < eOperandType::Float && this->data.find('.') != std::string::npos)
            throw ParserException("Can't set float in Int");
        this->value = get_data_num();
    }
}

std::string Parser::get_cmd() {
    return this->command;
}

bool Parser::eof() {
    if(this->stream.eof())
        return true;
    return false;
}