#include "unix_path.hh"

#include <sstream>

std::string UnixPath::to_string() const
{
    std::basic_ostringstream<char> stream;
    size_t i = 0;
    while (i < path_.size())
    {
        stream << '/';
        stream << path_.at(i);
        i++;
    }
    if (!final_)
        stream << '/';

    return stream.str();
}
