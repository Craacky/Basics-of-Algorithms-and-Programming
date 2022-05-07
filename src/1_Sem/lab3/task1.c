#include <math.h>
#include <stdio.h>
#include <string.h>

void main(void) {
    float x, y;
    printf("Enter x and y:\n");
    scanf("%f  %f", &x, &y);
    double numerator = 3.3 * pow(10, -4) * pow(logf(pow(x, 2) + pow(y, 2)), 3) + tanf(fabs(x));
    double denominator = 1.5 * sinf(pow(x, 2) + pow(y, 2)) * cosf(sqrt(x));
    double fraction = numerator / denominator;
    printf("Result: %f\n", fraction);
}