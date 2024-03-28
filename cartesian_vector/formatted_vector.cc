#include "formatted_vector.hh"

#include "state_saver.hh"
#include "vector.hh"

FormattedVector::FormattedVector(double x, double y)
    : FormatNumericalData("[ ", " ]", 12, true, true)
    , Vector(x, y)
{}

FormattedVector::FormattedVector(Vector vec)
    : FormatNumericalData("[ ", " ]", 12, true, true)
    , Vector(vec.get_x(), vec.get_y())
{}

std::ostream& operator<<(std::ostream& os, const FormattedVector& vect)
{
    {
        StateSaver save(os);
        vect.formatOs(os);
        os << vect.prefix << vect.x_ << " , " << vect.y_ << vect.suffix;
    }
    return os;
}
