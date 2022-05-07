#include<stdio.h>

int main(void) {
	float a, b;
	printf("Input Number a:");
	scanf("%f", &a);
	printf("Input Number b:");
	scanf("%f", &b);
	printf(" %-10.4f ", a);
	printf(" %-8.3f \n", a / 2);
	printf(" %-10.4f ", b);
	printf(" %-8.3f  \n", b / 2);
	return 0;
}