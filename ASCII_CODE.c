#include <stdio.h>

/*A programme to show the ASCII code corresponding to each alphabet in English*/
int main () {
	char c = 'A';
	printf("--- These are uppercase letters in English ---\n\n");
	do {
		printf("\tThe ASCII code of character '%c' is %d\n", c, c);
		c++;
		if (c == '[') {
			c = 'a';
			printf("\n--- These are lowercase letters in English ---\n\n");
		}
	} while (c != 'z');
	
}