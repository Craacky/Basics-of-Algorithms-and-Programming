#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a = 9, b = 1, c, d, e, f, g;
    c = a / b;
    d = a % b;
    e = a * b;
    f = a - b;
    g = a + b;
    printf("c = %d\nd = %d\ne = %d\nf = %d\ng = %d", c, d, e, f, g);
    system("pause");
    return 0;
}