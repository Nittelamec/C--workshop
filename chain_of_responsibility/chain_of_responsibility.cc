#include "director.hh"
#include "president.hh"
#include "vice_president.hh"

int main()
{
    President p;
    VicePresident vp;
    vp.set_successor(&p);
    Director d;
    d.set_successor(&vp);

    d.handle_request(1);
    d.handle_request(10);
    d.handle_request(2);
    d.handle_request(5);
    d.handle_request(4);
    d.handle_request(2);
    d.handle_request(9);

    return 0;
}
