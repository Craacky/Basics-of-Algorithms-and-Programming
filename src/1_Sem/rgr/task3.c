#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter num = ");
    scanf("%d", &num);
    int x = ((num > -120 && num <= -5.36) || (num > 10.5 && num < 36) && num != 27) ? 1 : 0;
    printf("True(1) or False(0) = (%d)", x);
    return 0;
}