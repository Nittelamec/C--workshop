#include <cassert>
#include <iostream>

#include "builder.hh"
#include "compute_visitor.hh"
#include "print_visitor.hh"

void test(const std::string& input, int expected, bool div_zero = false)
{
    auto builder = Builder(input);
    auto t = builder.build();
    auto cv = visitor::ComputeVisitor();
    auto pv = visitor::PrintVisitor();

    try
    {
        t->accept(cv);
        t->accept(pv);
        std::cout << std::endl;
    }
    catch (std::overflow_error& e)
    {
        assert(div_zero);
    }

    assert(cv.get_value() == expected);
}

int main()
{
    test("+ 4 32", 36);
    test("+ - 4 32 3", -25);
    test("+ 432 / 23 2", 443);
    test("- 3 -2", 5);

    test("* 32 / 89 + 34 -384", 0);
    test("/ + * 2 5 -54 0", 0, true);
    test("* 32 / 89 + 34 -34", 0, true);

    test("- / + / * * 2 3 4 2 321 -65 42", -47);
    test("+ / * - - * 32 -567 -22 785 -44 322 12", 2595);
    test("- 432 * 4364 / -7422 + 22 21", 751040);

    return 0;
}
