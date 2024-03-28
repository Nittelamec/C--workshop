#include "read_info.hh"

#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>

DirectoryInfo read_info(std::istream& os)
{
    std::string token;
    std::getline(os, token);

    if (token.empty())
        return DirectoryInfo();

    std::istringstream stream(token);

    std::string name;
    size_t size;
    uint16_t rights;
    std::string owner;

    stream >> name >> size >> std::oct >> rights >> std::dec >> owner;

    if (!stream.eof() || name.empty() || owner.empty())
        return DirectoryInfo();

    return DirectoryInfo(name, size, rights, owner);
}
