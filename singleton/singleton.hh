#pragma once

#include <iostream>

template <class T>
class Singleton
{
protected:
    Singleton() = default;
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;

public:
    static T& instance();
};

#include "singleton.hxx"

class Logger : public Singleton<Logger>
{
    friend Logger& Singleton<Logger>::instance();
    Logger(){};

public:
    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();
};
