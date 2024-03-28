#pragma once

#include <unordered_map>

template <class T>
class Exist
{
public:
    bool operator()(const T& t);

private:
    std::unordered_map<T, bool> table_;
};

#include "exist.hxx"
