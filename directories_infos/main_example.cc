#include <fstream>
#include <iomanip>
#include <iostream>

#include "directory_info.hh"
#include "read_info.hh"

int main(int argc, char** argv)
{
    if (argc < 2)
        return 1;

    auto file = std::ifstream(argv[1]);

    DirectoryInfo dir_info;

    while ((dir_info = read_info(file)).is_valid())
    {
        std::stringstream str_stream;
        str_stream << dir_info.get_name() << ' ' << dir_info.get_size() << ' '
                   << std::oct << dir_info.get_rights() << std::dec << ' '
                   << dir_info.get_owner() << '\n';

        dir_info = read_info(str_stream);
        if (!dir_info.is_valid())
            break;

        std::cout << dir_info.get_name() << '|' << dir_info.get_size() << '|'
                  << std::oct << dir_info.get_rights() << std::dec << '|'
                  << dir_info.get_owner() << '\n';
    }
}
