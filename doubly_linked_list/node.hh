#pragma once

#include <memory>

class Node
{
public:
    Node(int v);

    int get_val() const;
    void set_val(int val);

    std::shared_ptr<Node> get_next() const;
    void set_next(std::shared_ptr<Node> next);

    std::shared_ptr<Node> get_prev() const;
    void set_prev(std::shared_ptr<Node> prev);

private:
    int val_;
    std::shared_ptr<Node> next_;
    std::weak_ptr<Node> prev_;
};
