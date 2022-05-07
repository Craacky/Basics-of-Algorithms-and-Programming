#include <stdio.h>

int main()
{
    unsigned int number;
    unsigned int result = 0u;
    unsigned int multiplier = 1u;
    printf("Enter number: ");
    scanf("%u", &number);
    while (number)
    {
        unsigned int remains = number % 10;
        if (remains != 0u && remains != 5)
        {
            result += remains * multiplier;
            multiplier *= 10;
        }
        number /= 10u;
    }
    printf("Result = [%u]", result);
    return 0;
}