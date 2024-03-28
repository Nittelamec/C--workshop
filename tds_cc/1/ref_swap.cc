#include <iostream>

void ref_swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void ptr_swap(int* a, int* b)
{
    if (a == nullptr || b == nullptr)
        return;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 3;
    int b = 19;

    std::cout << "Before: a = " << a << ", b = " << b << '\n';
    ref_swap(a, b);
    std::cout << "After: a = " << a << ", b = " << b << '\n';
    std::cout << "Before: a = " << a << ", b = " << b << '\n';
    ptr_swap(&a, &b);
    std::cout << "After: a = " << a << ", b = " << b << '\n';

    return 0;
}
