#include "int_container.hh"

#include <iostream>

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::unique_ptr<int[]>(new int[size]))
{}

void MyIntContainer::print() const
{
    size_t i = 0;
    while (i < current_size_)
    {
        std::cout << elems_.get()[i];
        if (i + 1 < current_size_)
            std::cout << " | ";
        i++;
    }
    std::cout << '\n';
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ >= max_size_)
        return false;
    elems_.get()[current_size_] = elem;
    current_size_ += 1;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
        return std::nullopt;
    int elem = elems_.get()[current_size_ - 1];
    current_size_ -= 1;
    return elem;
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
        return std::nullopt;
    return elems_.get()[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    size_t i = 0;
    while (i < current_size_)
    {
        if (elems_.get()[i] == elem)
            return i;
        i++;
    }
    return std::nullopt;
}

void MyIntContainer::sort()
{
    size_t i = 1;
    while (i < current_size_)
    {
        size_t j = 0;
        while (j < i)
        {
            if (elems_[i] < elems_[j])
            {
                int tmp = elems_[j];
                elems_[j] = elems_[i];
                elems_[i] = tmp;
            }
            j++;
        }
        i++;
    }
}

bool MyIntContainer::is_sorted() const
{
    size_t i = 0;
    while (i + 1 < current_size_)
    {
        if (elems_[i + 1] < elems_[i])
            return false;
        i++;
    }
    return true;
}
