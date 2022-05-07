#include <stdio.h>

int Fmain(void)
{
    int a, b;
    printf("Input num a:");
    scanf("%d", &a);
    printf("Input num b:");
    scanf("%d", &b);
    printf("----------------------------\n");
    int c = a & b;
    printf("Bitwise conjuction: %d\n", c);
    int d = a | b;
    printf("Bitwise disjunction: %d\n", d);
    int e = a ^ b;
    printf("Bitwise exclusive: %d\n", e);
    int f = ~a;
    printf("Ditwise inversion: %d\n", f);
    int g = a << b;
    printf("Left shift: %d \n", g);
    int h = a >> b;
    printf("Right shift: %d\n", h);
    printf("----------------------------\n");
}