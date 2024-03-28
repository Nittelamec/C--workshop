#pragma once

template <class IT, class F>
void my_foreach(IT begin, IT end, F function)
{
    while (begin != end)
    {
        function(*begin);
        begin++;
    }
}
