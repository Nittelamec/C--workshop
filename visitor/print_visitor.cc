#include "print_visitor.hh"

#include <iostream>

#include "add.hh"
#include "div.hh"
#include "leaf.hh"
#include "mul.hh"
#include "node.hh"
#include "sub.hh"
#include "visitor.hh"

namespace visitor
{
    void PrintVisitor::visit(const tree::Tree& e)
    {
        e.accept(*this);
    }
    void PrintVisitor::visit(const tree::Node& e)
    {
        e.accept(*this);
    }
    void PrintVisitor::visit(const tree::AddNode& e)
    {
        std::cout << '(';
        e.get_lhs()->accept(*this);
        std::cout << " + ";
        e.get_rhs()->accept(*this);
        std::cout << ')';
    }
    void PrintVisitor::visit(const tree::SubNode& e)
    {
        std::cout << '(';
        e.get_lhs()->accept(*this);
        std::cout << " - ";
        e.get_rhs()->accept(*this);
        std::cout << ')';
    }
    void PrintVisitor::visit(const tree::MulNode& e)
    {
        std::cout << '(';
        e.get_lhs()->accept(*this);
        std::cout << " * ";
        e.get_rhs()->accept(*this);
        std::cout << ')';
    }
    void PrintVisitor::visit(const tree::DivNode& e)
    {
        std::cout << '(';
        e.get_lhs()->accept(*this);
        std::cout << " / ";
        e.get_rhs()->accept(*this);
        std::cout << ')';
    }
    void PrintVisitor::visit(const tree::Leaf& e)
    {
        std::cout << e.get_value();
    }
} // namespace visitor
