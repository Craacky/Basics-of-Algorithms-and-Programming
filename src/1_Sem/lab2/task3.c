#include <stdio.h>

int main()
{
    int Y;
    float A, a, b, c, d, e;
    printf("----------------------------\n");
    printf("Input A:");
    scanf("%f", &A);
    printf("----------------------------\n");
    printf("Enter span limits:\n");
    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);
    printf("----------------------------\n");
    Y = ((A >= a && A < b) || (A > c && A <= d) && A != e) ? 1 : 0;
    printf("True(1) or False(0): %d\n", Y);
    printf("----------------------------\n");
    return 0;
}