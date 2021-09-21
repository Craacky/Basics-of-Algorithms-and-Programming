#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Input num a:");
    scanf("%d", &a);
    printf("Input num b:");
    scanf("%d", &b);
    c = a + b;
    printf("Total %d \n", c);
    return 0;
}