#include "forward_multiplication.hh"

outer_lambda_type mult_by = [](int lhs) -> inner_lambda_type {
    return [lhs](int rhs) -> int { return lhs * rhs; };
};
