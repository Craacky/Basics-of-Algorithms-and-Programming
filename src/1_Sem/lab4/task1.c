#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    float x, xp, xn;
    float result1 = 0.0f;
    float result2 = 0.0f;

    printf("Enter x: ");
    scanf("%f", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    if (n < 2)
        return 1;

    for (int i = 0; i < n; ++i)
    {
        result1 += (x * i + 1) + (x * i);
        printf("Enter x%d: ", i + 1);
        scanf("%f", &xn);
        if (i > 0)
            result2 += xp / fabs(xn) + 1.0f;
        xp = xn;
    }
    printf("Sum = [%.2f]\n", result1);
    printf("Result = [%.2f] ", result2);

    return 0;
}