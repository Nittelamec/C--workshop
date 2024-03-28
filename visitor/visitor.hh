#pragma once

namespace tree
{
    class Tree;
    class Node;
    class AddNode;
    class SubNode;
    class MulNode;
    class DivNode;
    class Leaf;
} // namespace tree

namespace visitor
{
    class Visitor
    {
    public:
        virtual void visit(const tree::Tree& e);
        virtual void visit(const tree::Node& e) = 0;
        virtual void visit(const tree::AddNode& e) = 0;
        virtual void visit(const tree::SubNode& e) = 0;
        virtual void visit(const tree::MulNode& e) = 0;
        virtual void visit(const tree::DivNode& e) = 0;
        virtual void visit(const tree::Leaf& e) = 0;
    };
} // namespace visitor

#include "visitor.hxx"
