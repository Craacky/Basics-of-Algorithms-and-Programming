#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Input num a: ");
    scanf("%d", &a);
    printf("Input num b: ");
    scanf("%d", &b);
    int c = a + b;
    int d = a - b;
    int e = a * b;
    int f = a / b;
    int g = a % b;
    printf("------------------------\nSum: %d\nDistraction: %d\nMultiplication: %d\nDivision: %d\nRemainder division: %d ", c, d, e, f, g);
}