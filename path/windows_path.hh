#pragma once

#include "path.hh"

class WindowsPath : public Path
{
public:
    WindowsPath(char c);
    std::string to_string() const override;
    Path& join(const std::string& tail, bool is_file = false) override;

private:
    const char disk_;
    bool is_file_invalid(const std::string& name) const
    {
        if (name.find_first_of("\":|?*", 0, 5) != std::string::npos)
            return true;
        return false;
    }
};
