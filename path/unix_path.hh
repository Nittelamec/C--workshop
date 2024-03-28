#pragma once

#include <string>

#include "path.hh"

class UnixPath : public Path
{
public:
    std::string to_string() const override;
};
