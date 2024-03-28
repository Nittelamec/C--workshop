#include "compute_visitor.hh"

#include <iostream>
#include <stdexcept>

#include "add.hh"
#include "div.hh"
#include "leaf.hh"
#include "mul.hh"
#include "node.hh"
#include "sub.hh"
#include "visitor.hh"

namespace visitor
{
    void ComputeVisitor::visit(const tree::Tree& e)
    {
        e.accept(*this);
    }
    void ComputeVisitor::visit(const tree::Node& e)
    {
        e.accept(*this);
    }
    void ComputeVisitor::visit(const tree::AddNode& e)
    {
        e.get_lhs()->accept(*this);
        int lhs_val = value_;
        e.get_rhs()->accept(*this);
        int rhs_val = value_;
        value_ = lhs_val + rhs_val;
    }
    void ComputeVisitor::visit(const tree::SubNode& e)
    {
        e.get_lhs()->accept(*this);
        int lhs_val = value_;
        e.get_rhs()->accept(*this);
        int rhs_val = value_;
        value_ = lhs_val - rhs_val;
    }
    void ComputeVisitor::visit(const tree::MulNode& e)
    {
        e.get_lhs()->accept(*this);
        int lhs_val = value_;
        e.get_rhs()->accept(*this);
        int rhs_val = value_;
        value_ = lhs_val * rhs_val;
    }
    void ComputeVisitor::visit(const tree::DivNode& e)
    {
        e.get_lhs()->accept(*this);
        int lhs_val = value_;
        e.get_rhs()->accept(*this);
        int rhs_val = value_;
        if (rhs_val == 0)
            throw std::overflow_error("Divide by zero exception");
        value_ = lhs_val / rhs_val;
    }

    void ComputeVisitor::visit(const tree::Leaf& e)
    {
        value_ = std::atoi(e.get_value().c_str());
    }

    int ComputeVisitor::get_value() const
    {
        return value_;
    }
} // namespace visitor
