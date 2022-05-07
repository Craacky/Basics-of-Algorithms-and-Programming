#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a = 9, b = 1;
    int c = ++a * b;
    int d = a-- + b++;
    int e = a - b;
    printf("c = %d\nd = %d\ne = %d", c, d, e);
    return 0;
}