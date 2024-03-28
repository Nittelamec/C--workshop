#include "stdin_to_file.hh"

#include <fstream>
#include <iostream>
#include <string>

ssize_t stdin_to_file(const std::string& filename)
{
    std::ofstream file;
    file.open(filename);
    if (!file.is_open())
        std::cerr << "Could not open the file " << filename;

    int cpt = 0;
    std::string token;

    while (std::cin >> token)
    {
        file << token << '\n';
        cpt += 1;
    }

    return cpt;
}
