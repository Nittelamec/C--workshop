#pragma once

#include <istream>

#include "directory_info.hh"

DirectoryInfo read_info(std::istream& os);
