#pragma once

#include "format_numerical_data.hh"
#include "vector.hh"

struct FormattedVector
    : FormatNumericalData
    , Vector
{
    FormattedVector() = default;
    FormattedVector(double x, double y);
    FormattedVector(Vector vec);

    friend std::ostream& operator<<(std::ostream& os,
                                    const FormattedVector& vect);
};

std::ostream& operator<<(std::ostream& os, const FormattedVector& vect);
