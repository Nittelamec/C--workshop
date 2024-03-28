#include "lookup_table.hh"

#include <optional>

std::optional<long> LookupTable::get(int x)
{
    if (!table_.contains(x))
        return std::nullopt;
    else
        return table_.find(x)->second;
}

void LookupTable::set(int x, long value)
{
    table_.emplace(x, value);
}
