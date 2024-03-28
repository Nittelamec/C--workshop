#include "vector.hh"

Vector::Vector(double x, double y)
    : x_(x)
    , y_(y)
{}

double Vector::get_x() const
{
    return x_;
}

double Vector::get_y() const
{
    return y_;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    x_ += rhs.get_x();
    y_ += rhs.get_y();
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    x_ -= rhs.get_x();
    y_ -= rhs.get_y();
    return *this;
}

Vector& Vector::operator*=(double scalar)
{
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    Vector res(lhs.get_x() + rhs.get_x(), lhs.get_y() + rhs.get_y());
    return res;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    Vector res(lhs.get_x() - rhs.get_x(), lhs.get_y() - rhs.get_y());
    return res;
}

Vector operator*(const Vector& lhs, double scalar)
{
    Vector res(lhs.get_x() * scalar, lhs.get_y() * scalar);
    return res;
}

Vector operator*(double scalar, const Vector& rhs)
{
    Vector res(rhs.get_x() * scalar, rhs.get_y() * scalar);
    return res;
}

double operator*(const Vector& lhs, const Vector& rhs)
{
    double res = lhs.get_x() * rhs.get_x() + lhs.get_y() * rhs.get_y();
    return res;
}
