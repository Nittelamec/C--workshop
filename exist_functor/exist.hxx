#pragma once

#include "exist.hh"

template <class T>
bool Exist<T>::operator()(const T& t)
{
    if (table_.contains(t))
        return true;
    else
    {
        table_.insert({ t, true });
        return false;
    }
}
