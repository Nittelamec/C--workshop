#include "regiment.hh"

void Regiment::join_by(Regiment& r)
{
    size_t i = 0;
    while (i < r.soldiers_.size())
    {
        soldiers_.push_back(r.soldiers_.at(i));
        i += 1;
    }
    r.soldiers_.clear();
}

size_t Regiment::count() const
{
    return soldiers_.size();
}

void Regiment::add_soldier(Soldier& s)
{
    soldiers_.push_back(s);
}

void Regiment::print_state() const
{
    size_t i = 0;
    while (i < soldiers_.size())
    {
        soldiers_.at(i).get().print_state();
        i += 1;
    }
}

void Regiment::scream() const
{
    size_t i = 0;
    while (i < soldiers_.size())
    {
        soldiers_.at(i).get().scream();
        i += 1;
    }
}
