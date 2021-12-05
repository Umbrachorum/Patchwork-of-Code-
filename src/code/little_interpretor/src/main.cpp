
#include <fstream>
#include "Core.hpp"
#include "extern_lib.hpp"

int main(int ac, char **av)
{
    Core c;
    if(ac == 2) {
        std::ifstream fd(av[1]);
        if (fd.fail() || is_empty(fd))
            return 84;
        return c.loop_reading(fd);
    }
    if(ac == 1){
        return c.loop_reading(std::cin);
    }
    return 84;
}