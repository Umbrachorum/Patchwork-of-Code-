
#include <fstream>
#include "gtest/gtest.h"
#include "Core.hpp"
#include "extern_lib.hpp"

TEST(Core, testing_switch_command_wrong)
{
    Core c;
    std::ifstream fd("example/example1.txt");
    Parser p(fd);
    try {
        c.command_handler(p);
        FAIL() << "Wrong cmd";
    } catch (CoreException const &e) {
        ASSERT_EQ(0, strcmp("Wrong instruction", e.msg()));
        ASSERT_EQ(0, strcmp("Core Exception", e.type()));
    }   catch (...) {
        FAIL() << "Expected exception fail with handler switch command";
    }
}

TEST(Core, loop_reading) {
    Core c;
    std::ifstream fd("example/empty.txt");
    ASSERT_EQ(true, is_empty(fd));
}
