#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    unsigned char a = 9, b = 1, c, d, e, f, g, h;
    c = a & b;
    d = a | b;
    e = a ^ b;
    f = a << b;
    g = a >> b;
    h = ~a;
    printf("c = %d\nd = %d\ne = %d\nf = %d\ng = %d\nh = %d", c, d, e, f, g, h);
    return 0;
}