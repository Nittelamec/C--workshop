#include "list.hh"

#include <memory>
#include <optional>

#include "node.hh"

List::List()
    : nb_elts_(0)
    , first_(nullptr)
    , last_(nullptr)
{}

void List::push_front(int i)
{
    std::shared_ptr new_node_shared = std::make_shared<Node>(i);
    new_node_shared->set_prev(nullptr);

    if (length() == 0)
    {
        first_ = new_node_shared;
        last_ = first_;
    }
    else
    {
        new_node_shared->set_next(first_);
        first_->set_prev(new_node_shared);
        first_ = new_node_shared;
    }
    nb_elts_++;
}

void List::push_back(int i)
{
    std::shared_ptr new_node_shared = std::make_shared<Node>(i);
    new_node_shared->set_next(nullptr);

    if (first_ == nullptr)
    {
        first_ = new_node_shared;
        last_ = first_;
    }
    else
    {
        new_node_shared->set_prev(last_);
        last_->set_next(new_node_shared);
        last_ = new_node_shared;
    }
    nb_elts_++;
}

std::optional<int> List::pop_front()
{
    if (length() == 0)
        return std::nullopt;
    else if (length() == 1)
    {
        int val = first_->get_val();
        first_ = nullptr;
        last_ = nullptr;
        nb_elts_--;
        return val;
    }
    else
    {
        int val = first_->get_val();
        first_->get_next()->set_prev(nullptr);
        first_ = first_->get_next();
        nb_elts_--;
        return val;
    }
}

std::optional<int> List::pop_back()
{
    if (length() == 0)
        return std::nullopt;
    else if (length() == 1)
    {
        int val = first_->get_val();
        first_ = nullptr;
        last_ = nullptr;
        nb_elts_--;
        return val;
    }
    else
    {
        int val = last_->get_val();
        last_->get_prev()->set_next(nullptr);
        last_ = last_->get_prev();
        nb_elts_--;
        return val;
    }
}

void List::print(std::ostream& os) const
{
    if (length() == 0)
    {}
    else if (length() == 1)
        os << first_->get_val();
    else
    {
        std::shared_ptr<Node> tmp(first_);
        while (tmp != nullptr)
        {
            os << tmp->get_val();
            if (tmp->get_next() != nullptr)
                os << " ";
            tmp = tmp->get_next();
        }
    }
}

size_t List::length() const
{
    return nb_elts_;
}
