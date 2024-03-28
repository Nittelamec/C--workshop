#pragma once

#include "node.hh"

namespace tree
{
    class AddNode : public Node
    {
    public:
        AddNode(const std::string& value, std::shared_ptr<Tree> lhs,
                std::shared_ptr<Tree> rhs);
        void accept(visitor::Visitor& v) const;
    };
} // namespace tree
