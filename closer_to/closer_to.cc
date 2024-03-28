#include "closer_to.hh"

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(int a, int b) const
{
    int dist_a = i_ > a ? i_ - a : a - i_;
    int dist_b = i_ > b ? i_ - b : b - i_;
    if (dist_a == dist_b)
        return (b > a);
    else
        return (dist_b > dist_a);
}
