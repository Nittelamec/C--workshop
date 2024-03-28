#include "dnl.hh"

#include <algorithm>
#include <numeric>
#include <vector>

size_t min_elt_length(const std::vector<std::string>& req)
{
    auto it = std::min_element(req.begin(), req.end(),
                               [](std::string s, std::string s2) -> bool {
                                   return (s.length() < s2.length());
                               });
    return it->length();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    auto it = std::max_element(req.begin(), req.end(),
                               [](std::string s, std::string s2) -> bool {
                                   return (s.length() < s2.length());
                               });
    return it->length();
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    return std::transform_reduce(
        req.begin(), req.end(), 0,
        [](std::size_t a, std::size_t b) -> std::size_t { return a + b; },
        [](std::string s) -> std::size_t { return s.length(); });
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    return std::count(req.begin(), req.end(), elt);
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    std::vector<std::string> cpy(req);
    std::sort(cpy.begin(), cpy.end());
    auto it = std::unique(cpy.begin(), cpy.end());
    return std::distance(it, cpy.end());
}
