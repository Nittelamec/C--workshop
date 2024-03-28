#include "path.hh"

Path& Path::join(const std::string& tail, bool is_file)
{
    if (final_)
        return *this;
    path_.push_back(tail);
    if (is_file)
        final_ = true;
    return *this;
}
