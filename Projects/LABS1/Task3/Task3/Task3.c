#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char a;
	char b[10];
	printf("Input char:");
	scanf("%c", &a);
	printf("Input string:");
	scanf("%s", &b);
	printf("Char: %c \n", a);
	printf("String: %s \n", b);
	return 0;
}