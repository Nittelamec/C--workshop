#pragma once

#include <memory>

#include "tree.hh"

namespace tree
{
    class Node : public Tree
    {
    public:
        Node(const std::string& value, std::shared_ptr<Tree> lhs,
             std::shared_ptr<Tree> rhs);
        ~Node();

        std::shared_ptr<const Tree> get_lhs() const;
        void set_lhs(std::shared_ptr<const Tree> t);
        std::shared_ptr<const Tree> get_rhs() const;
        void set_rhs(std::shared_ptr<const Tree> t);

        void accept(visitor::Visitor& v) const;

    private:
        std::shared_ptr<const Tree> lhs_;
        std::shared_ptr<const Tree> rhs_;
    };
} // namespace tree

#include "node.hxx"
