#pragma once

#include "singleton.hh"

template <class T>
T& Singleton<T>::instance()
{
    static T t;
    return t;
}
