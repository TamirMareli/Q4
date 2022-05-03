#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main() {
	int x = 100;
	char c;
	printf("%d\n", x);
	c = str(x);
	printf("%c\n", c);
	x++;
	printf("%d\n", x);
}
