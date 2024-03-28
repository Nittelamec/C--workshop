#include "handler.hh"

#include <iostream>

Handler::Handler(Handler* next)
    : next_(next)
{}

void Handler::set_successor(Handler* h)
{
    next_ = h;
}

void Handler::forward_request(int level)
{
    if (next_ == nullptr)
        std::cout << "Nobody can handle this request\n";
    else
        next_->handle_request(level);
}
