#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    float x, y;
    float res1, res2, res3, res4;
    printf("Enter x and y:\n");
    scanf("%f  %f", &x, &y);
    float zone1 = x > 0 && x < 3 && y > 0 && y < 2;
    float zone2 = x < 0 && x > -2 && y > 0 && y < 2;
    float zone3 = x > 0 && x < 3 && y < 0 && y > -2;
    float zone4 = x < 0 && x > -2 && y < 0 && y > -2;
    res1 = tanf(x + y);
    res2 = 2.72;
    res3 = atan(x + y);
    res4 = logf(fabs(x + y));
    int zone;
    if (zone1)
    {
        zone = 1;
    }
    else if (zone2)
    {
        zone = 2;
    }
    else if (zone3)
    {
        zone = 3;
    }
    else if (zone4)
    {
        zone = 4;
    }
    else
        zone = 0;
    switch (zone)
    {
    case 0:
        printf("The point does not fall into any zone");
        break;
    case 1:
        printf("Result 1 zone: = %f", res1);
        break;
    case 2:
        printf("Result 2 zone: = %f", res2);
        break;
    case 3:

        printf("Result 3 zone: = %f", res3);
        break;
    case 4:
        printf("Result 4 zone: = %f", res4);
        break;
    }
    return 0;
}