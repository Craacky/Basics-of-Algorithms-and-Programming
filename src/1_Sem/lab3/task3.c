#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y, a, b;
    x = 0.f;
    a = 0.f;
    while (x > -1)
    {
        printf("Enter x(polyline), [x < 0]: ");
        scanf("%f", &x);
    }
    while (a < 1)
    {
        printf("Enter a (line), [a > 0]: ");
        scanf("%f", &a);
    }
    printf("Enter b(line): ");
    scanf("%f", &b);
    if (x < -1)
    {
        y = -2;
        x = (y - b) / a;
        printf("Coordinates: [ %.4f, %.4f ]", x, y);
    }
    else if (x == -1)
    {
        y = a * x + b;
        printf("Coordinates: [ %.4f ,%.2f ]", x, y);
    }
    return 0;
}