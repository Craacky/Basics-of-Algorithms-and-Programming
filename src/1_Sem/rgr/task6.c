#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a = 9, b = 1, c;
    c = (a >= 4 && (a & b) < 10) ? 4 / 5 : 1;
    printf("True(res = 4 / 5) or False(1) = %d", c);
    return 0;
}