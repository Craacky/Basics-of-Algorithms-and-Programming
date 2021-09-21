#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    float a, b, c;
    printf("Input num a:");
    scanf("%f", &a);
    printf("Input num b:");
    scanf("%f", &b);
    c = a * b;
    printf("RESULT: %.3f ", c);
    return 0;
}