#include <stdio.h>

int main(void)
{
    int a, b;
    printf("--------------------------------\n");
    printf("Input num a:");
    scanf("%d", &a);
    printf("--------------------------------\n");
    printf("Input num b:");
    scanf("%d", &b);
    int *c, *d;
    c = &a;
    d = &b;
    printf("--------------------------------\n");
    printf("Total b value: %d\n", *d -= 10);
    printf("--------------------------------\n");
    printf("Multiplication a and b: %d\n", a = *c * *d);
    printf("--------------------------------\n");
}
