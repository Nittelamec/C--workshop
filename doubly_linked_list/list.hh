#pragma once

#include <iostream>
#include <optional>

#include "node.hh"

class List
{
public:
    List();

    void push_front(int i);
    void push_back(int i);
    std::optional<int> pop_front();
    std::optional<int> pop_back();
    void print(std::ostream& os) const;
    size_t length() const;

private:
    size_t nb_elts_;
    std::shared_ptr<Node> first_;
    std::shared_ptr<Node> last_;
};
