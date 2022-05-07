#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter x : ");
    scanf("%d", &x);
    int res1 = (x < -6) ? 1 : 0;
    int res2 = (x >= -6 && x < 1) ? 1 : 0;
    int res3 = (x >= 1) ? 1 : 0;
    switch (res1)
    {
    case 1:
        printf("cos(-x) = %p ", cos(-x));
        break;
    }
    switch (res2)
    {
    case 1:
        printf("pow(x,5) = %.2f", pow(x, 5));
        break;
    }
    switch (res3)
    {
    case 1:
        printf("sqrt(x) = %.2f", sqrt(x));
        break;
    }
    return 0;
}