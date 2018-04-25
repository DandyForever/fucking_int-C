#include <iostream>
#include "stupid_int.h"

int main()
{
    std::cout << 0;
    demoint a;
    demoint b;
    int k = 3;
    b = 6 + k;
    a = 5;
    a += b;
    a += b;
    a += b;
    std::cout << a;
    demoint c;
    c = -b;
    std::cout << a << b << c;
    demoint d;
    demoint e;
    demoint p;
    d = 10;
    e = 5;
    p = 4;
    p *= k;
    std::cout << '\n' << d << e << p;
    return 0;
}
