#include "adapt_legacy_rectangle.hh"

#include <iostream>

#include "legacy_rectangle.hh"

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

AdaptLegacyRectangle::~AdaptLegacyRectangle()
{}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << rect_.get_x1();
    std::cout << " y: " << rect_.get_y1();
    std::cout << '\n';

    std::cout << "height: " << std::abs(rect_.get_y2() - rect_.get_y1());
    std::cout << '\n';
    std::cout << "width: " << std::abs(rect_.get_x2() - rect_.get_x1());
    std::cout << '\n';
}

unsigned AdaptLegacyRectangle::area() const
{
    return rect_.compute_area();
}
