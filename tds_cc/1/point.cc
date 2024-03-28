#include <iostream>

class Point
{
public:
    void display() const;
    void move(int x, int y);

private:
    int x_;
    int y_;
};

void Point::display() const
{
    std::cout << "x :" << x_;
    std::cout << "y :" << y_;
}

void Point::move(int x, int y)
{
    x_ += x;
    y_ += y;
}
