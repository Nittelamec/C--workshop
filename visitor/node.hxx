#pragma once

#include "node.hh"

namespace tree
{
    inline std::shared_ptr<const Tree> Node::get_lhs() const
    {
        return lhs_;
    }

    inline void Node::set_lhs(std::shared_ptr<const Tree> t)
    {
        lhs_ = t;
    }

    inline std::shared_ptr<const Tree> Node::get_rhs() const
    {
        return rhs_;
    }

    inline void Node::set_rhs(std::shared_ptr<const Tree> t)
    {
        rhs_ = t;
    }
} // namespace tree
