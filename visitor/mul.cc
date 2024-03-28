#include "mul.hh"

#include "print_visitor.hh"
#include "visitor.hh"

namespace tree
{
    MulNode::MulNode(const std::string& value, std::shared_ptr<Tree> lhs,
                     std::shared_ptr<Tree> rhs)
        : Node(value, lhs, rhs)
    {}

    void MulNode::accept(visitor::Visitor& v) const
    {
        v.visit(*this);
    }
} // namespace tree
