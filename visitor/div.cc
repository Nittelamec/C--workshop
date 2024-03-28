#include "div.hh"

#include "print_visitor.hh"
#include "visitor.hh"

namespace tree
{
    DivNode::DivNode(const std::string& value, std::shared_ptr<Tree> lhs,
                     std::shared_ptr<Tree> rhs)
        : Node(value, lhs, rhs)
    {}

    void DivNode::accept(visitor::Visitor& v) const
    {
        v.visit(*this);
    }
} // namespace tree
