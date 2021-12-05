//
// Created by umbra on 12/07/2021.
//

#include <fstream>
#include <map>
#include <functional>

#include "Core.hpp"

int Core::loop_reading(std::istream &input) {
    std::string buffer;
    try {
        if(input.eof() || input.fail())
            return 84;
        Parser parser(input);
        while (true) {
            parser.get_input();
            if (parser.get_cmd() == "exit")
                return 0;
            if(!parser.get_cmd().empty() && parser.get_cmd() != "end")
                this->command_handler(parser);
            parser.clear_num();
        }
    } catch (const ParserException &exception) {
        std::cout << exception.what() << std::endl;
        return 84;
    }
    catch (const Exceptions &e) {
        std::cout << e.msg() << std::endl;;
        return 84;
    } catch (const std::exception &exception) {
        std::cout << exception.what() << std::endl;
        return 84;
    }
    return 0;
}

void Core::command_handler(Parser &parser)
{

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
    static const std::map<std::string, std::function<void(void)>> commands = {
            {"pop", [this]() -> void { my_stack.pop(); }},
            {"push", [this, &parser]() -> void {
                my_stack.push(Factory::createOperand(parser.get_type(),
                        parser.get_data_num()));
            }}, {"dump", [this]() -> void { my_stack.dump(); }},
            {"clear", [this]() -> void { my_stack.clear(); }},
            {"swap", [this]() -> void { my_stack.swap(); }},
            {"dup", [this]() -> void { my_stack.dup(); }},
            {"assert", [this, &parser]() -> void {
                if (!my_stack.expect(*Factory::createOperand(parser.get_type(),
                        parser.get_data_num())))
                    throw ArithmeticException("assertion failed!");
            }}, {"add", [this]() -> void { my_stack.add(); }},
            {"sub", [this]() -> void { my_stack.sub(); }},
            {"mul", [this]() -> void { my_stack.mul(); }},
            {"div", [this]() -> void { my_stack.div(); }},
            {"mod", [this]() -> void { my_stack.mod(); }},
            {"load", [this, &parser]() -> void {
                my_stack.load(parser.index_register());
            }}, {"store", [this, &parser]() -> void {
                my_stack.store(parser.index_register());
            }}, {"print", [this]() -> void { my_stack.print(); }},
            {"exit", []() -> void { exit(0); }}};
#pragma GCC diagnostic pop
    if (commands.count(parser.get_cmd()) == 0)
        throw CoreException("Wrong instruction");
    commands.find(parser.get_cmd())->second();
}