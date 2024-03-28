#include "windows_path.hh"

#include <sstream>

#include "path.hh"

WindowsPath::WindowsPath(char c)
    : disk_(c)
{}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (is_file_invalid(tail))
        return *this;
    return Path::join(tail, is_file);
}

std::string WindowsPath::to_string() const
{
    std::basic_ostringstream<char> stream;
    stream << disk_ << ':';

    size_t i = 0;
    while (i < path_.size())
    {
        stream << '\\';
        stream << path_.at(i);
        i++;
    }

    if (!final_)
        stream << '\\';
    return stream.str();
}
