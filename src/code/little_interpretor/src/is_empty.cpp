//
// Created by umbra on 15/07/2021.
//

#include "extern_lib.hpp"
#include <fstream>

bool is_empty(std::istream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}