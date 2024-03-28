#pragma once

#include "visitor.hh"

namespace visitor
{
    class ComputeVisitor : public Visitor
    {
    public:
        void visit(const tree::Tree& e) override;
        void visit(const tree::Node& e) override;
        void visit(const tree::AddNode& e) override;
        void visit(const tree::SubNode& e) override;
        void visit(const tree::MulNode& e) override;
        void visit(const tree::DivNode& e) override;
        void visit(const tree::Leaf& e) override;

        int get_value() const;

    private:
        int value_;
    };
} // namespace visitor
