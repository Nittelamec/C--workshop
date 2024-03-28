#include <iostream>

#include "dnl.hh"

int main(int argc, char** argv)
{
    if (argc < 2)
        return 1;

    std::vector<std::string> v(argv + 1, argv + argc);
    std::cout << "count be = " << count_elt(v, "be") << std::endl;
    std::cout << "min = " << min_elt_length(v) << std::endl;
    std::cout << "max = " << max_elt_length(v) << std::endl;
    std::cout << "sum = " << sum_elt_length(v) << std::endl;
    std::cout << "dup = " << count_duplicate(v) << std::endl;
    return 0;
}
