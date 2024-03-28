#pragma once

#include <cstdint>
#include <string>

class DirectoryInfo
{
public:
    DirectoryInfo() = default;
    DirectoryInfo(const std::string& name, size_t size, uint16_t rights,
                  const std::string& owner);
    const std::string& get_name() const;
    const std::string& get_owner() const;
    size_t get_size() const;
    uint16_t get_rights() const;
    bool is_valid() const;

private:
    std::string name_;
    size_t size_;
    uint16_t rights_;
    std::string owner_;
    bool is_valid_ = false;
};
