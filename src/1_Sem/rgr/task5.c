#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a = 9, b = 1;
    int *c, *d;
    c = &a;
    d = &b;
    *c = *c + 5;
    printf("*c = %d\n", *c);
    *c |= *d;
    printf("c = %d\nd = %d\n*c = %d", c, d, *c);

    return 0;
}