//
// Created by umbra on 12/07/2021.
//

#ifndef ABSVM_CORE_HPP
#define ABSVM_CORE_HPP

#include "Parser.hpp"
#include <cstring>
#include "Exceptions.hpp"
#include "Stack.hpp"

class Core {
public:
    Core() = default;
    ~Core() = default;
    int loop_reading(std::istream &input);
    void command_handler(Parser &parser);

private:
    Stack my_stack;
};


#endif //ABSVM_CORE_HPP
