#include "merge_sort.hh"

void merge_sort(iterator_type begin, iterator_type end)
{
    int dist = std::distance(begin, end);
    if (dist == 1)
        return;

    iterator_type p = begin;
    std::advance(p, dist / 2);

    merge_sort(begin, p);
    merge_sort(p, end);

    std::inplace_merge(begin, p, end);
}
