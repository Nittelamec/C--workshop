#include "president.hh"

#include <iostream>

#include "handler.hh"

void President::handle_request(int level)
{
    if (level <= 9)
        std::cout << "President handles\n";
    else
        Handler::forward_request(level);
}
