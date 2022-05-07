#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    printf("-----------------------\n");
    printf("Input num a: ");
    scanf("%d", &a);
    printf("-----------------------\n");
    printf("Input num b: ");
    scanf("%d", &b);
    printf("-----------------------\n");
    int c = --a + a * b + --b;
    printf("Result: %d\n", c);
    printf("-----------------------\n");
}