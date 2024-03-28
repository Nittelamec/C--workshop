#include "director.hh"

#include <iostream>

#include "handler.hh"

void Director::handle_request(int level)
{
    if (level <= 3)
        std::cout << "Director handles\n";
    else
        Handler::forward_request(level);
}
