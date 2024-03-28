#pragma once

template <typename T, typename T2 = T>
concept impl_modulo = requires(T t, T2 t2)
{
    t % t2;
    t2 % t;
};

template <typename T, typename T2 = T>
concept impl_bitwise_op = requires(T t, T2 t2)
{
    ~t;
    ~t2;
    t& t2;
    t2& t;
    t | t2;
    t2 | t;
    t ^ t2;
    t2 ^ t;
    t << t2;
    t2 << t;
    t >> t2;
    t2 >> t;
};

template <typename T, typename T2 = T>
concept impl_basic_op = requires(T t, T2 t2)
{
    +t;
    -t;
    +t2;
    -t2;
    t + t2;
    t2 + t;
    t - t2;
    t2 - t;
    t* t2;
    t2* t;
    t / t2;
    t2 / t;
};

template <typename T, typename T2 = T>
concept impl_arith_op = requires
{
    requires impl_basic_op<T, T2>;
    requires impl_bitwise_op<T, T2>;
    requires impl_modulo<T, T2>;
};
