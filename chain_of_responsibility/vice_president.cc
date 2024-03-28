#include "vice_president.hh"

#include <iostream>

#include "handler.hh"

void VicePresident::handle_request(int level)
{
    if (level <= 6)
        std::cout << "VicePresident handles\n";
    else
        Handler::forward_request(level);
}
