#pragma once

#include "tree.hh"

namespace tree
{
    inline const std::string& Tree::get_value() const
    {
        return value_;
    }

    inline void Tree::set_value(const std::string& s)
    {
        value_ = s;
    }
} // namespace tree
