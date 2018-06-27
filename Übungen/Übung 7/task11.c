#include <stdio.h>
void tausche (char*, char*);

int main(int argc, char** argv) {
	char a = 'B';
	char b = 'A';
	printf("Befor swap: a: %c, b: %c\n", a, b);
	tausche(&a , &b);
	printf("After swap: a: %c, b: %c", a, b);
}

void tausche (char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

