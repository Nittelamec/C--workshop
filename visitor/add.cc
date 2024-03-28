#include "add.hh"

#include "print_visitor.hh"
#include "visitor.hh"

namespace tree
{
    AddNode::AddNode(const std::string& value, std::shared_ptr<Tree> lhs,
                     std::shared_ptr<Tree> rhs)
        : Node(value, lhs, rhs)
    {}

    void AddNode::accept(visitor::Visitor& v) const
    {
        v.visit(*this);
    }
} // namespace tree
