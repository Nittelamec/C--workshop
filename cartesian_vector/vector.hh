#pragma once

struct Vector
{
public:
    Vector() = default;
    Vector(double x, double y);
    double get_x() const;
    double get_y() const;

    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*=(double scalar);

    friend Vector operator+(const Vector& lhs, const Vector& rhs);
    friend Vector operator-(const Vector& lhs, const Vector& rhs);
    friend Vector operator*(const Vector& lhs, double scalar);
    friend Vector operator*(double scalar, const Vector& rhs);
    friend double operator*(const Vector& lhs, const Vector& rhs);

protected:
    double x_ = 0;
    double y_ = 0;
};

Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator*(const Vector& lhs, double scalar);
Vector operator*(double scalar, const Vector& rhs);
double operator*(const Vector& lhs, const Vector& rhs);
