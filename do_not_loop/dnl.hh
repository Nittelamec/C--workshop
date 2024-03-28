#pragma once

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#define while forbidden_use_of_while
#define goto forbidden_use_of_goto
#define for forbidden_use_of_for

namespace std
{
#define for_each forbidden_use_of_for_each
} // namespace std

size_t min_elt_length(const std::vector<std::string>& req);
size_t max_elt_length(const std::vector<std::string>& req);
size_t sum_elt_length(const std::vector<std::string>& req);
size_t count_elt(const std::vector<std::string>& req, const std::string& elt);
size_t count_duplicate(const std::vector<std::string>& req);
