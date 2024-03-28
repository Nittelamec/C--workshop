#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in(input_filename);
    std::ofstream file_out(output_filename);

    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return;
    }
    if (!file_out.good())
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    std::string line;

    while (std::getline(file_in, line))
    {
        size_t pos = 0;
        while ((pos = line.find(src_token, pos)) != std::string::npos)
        {
            line.replace(pos, src_token.length(), dst_token);
            pos += dst_token.length();
        }
        file_out << line;
        file_out << '\n';
    }
}
