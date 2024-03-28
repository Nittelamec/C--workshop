#include <iostream>

#include "exist.hh"

int main()
{
    Exist<int> exist_int;
    Exist<std::string> exist_str;

    // Test with integers
    std::cout << std::boolalpha;
    std::cout << exist_int(1) << std::endl; // Prints false
    std::cout << exist_int(2) << std::endl; // Prints false
    std::cout << exist_int(1) << std::endl; // Prints true
    std::cout << exist_int(3) << std::endl; // Prints false

    // Test with strings
    std::cout << exist_str(std::string("Hello")) << std::endl; // Prints false
    std::cout << exist_str(std::string("World")) << std::endl; // Prints false
    std::cout << exist_str(std::string("Hello")) << std::endl; // Prints true
    std::cout << exist_str(std::string("C++")) << std::endl; // Prints false

    return 0;
}
