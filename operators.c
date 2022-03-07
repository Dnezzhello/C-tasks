#include <stdio.h>

int *to_binary(int x) {

	static int arr[8];
	int i, temp;

	for (i=0;i<8;i++) {
		arr[i] = x%2;
		x = x/2;
	}
	// reverse the array
	for (i=8-1;i>=8/2;i--) {
		temp = arr[i];
		arr[i] = arr[8-1-i];
		arr[8-1-i]= temp;
	}
	
	return arr;
}

void show_binary(int *p) {
	for (int i=0;i<8;i++) {
		if (i == 4) {
			printf(" ");
		}
		printf("%d", *(p+i));
	}
	printf("\n");
}

void arithmetic(int x, int y) {
	printf("x + y = %d\n", x+y);
	printf("x - y = %d\n", x-y);
	printf("x * y = %d\n", x*y);
	printf("x / y = %d\n", x/y);
	printf("x %% y = %d\n", x%y);
	printf("x++ = %d\n", x++);
	printf("x-- = %d\n", x--);
}

void relation(int x, int y) {
	if (x == y) {
		printf("x is equal to y\n");
	} else if (x != y ) {
		printf("x is not equal to y\n");
		if ( x > y) {
			printf("x is greater than y\n");
		} else {
			printf("x is less than y\n");
		}
	}
}

void logical(int x, int y, int z) {
	
	if (x > z && y > z) {
		printf("The condition 'x > z and y > z' is true\n");
	} else {
		printf("The condition 'x > z and y > z' is false\n");
	} 
	
	if (x > z || y > z) {
		printf("The condition 'x > z or y > z' is true\n");
	} else {
		printf("The condition 'x > z or y > z' is false\n");
	}
	
}

void bitwise(int x, int y) {
	
	printf("The binary form of %d is ", x);
	show_binary(to_binary(x));
	printf("The binary form of %d is ", y);
	show_binary(to_binary(y));
	
	// & 
	printf("x & y = ");
	show_binary(to_binary(x&y));
	// |
	printf("x | y = ");
	show_binary(to_binary(x|y));
	// ^ 
	printf("x ^ y = ");
	show_binary(to_binary(x^y));
	// ~ 
//	printf("~x = ");
//	show_binary(to_binary(~x));
	// << 
	printf("x << 2 = ");
	show_binary(to_binary(x<<2));
	// >> 
	printf("x >> 2 = ");
	show_binary(to_binary(x >> 2));
	
}

void assignment(int x, int y) {
	printf("value of x and y are %d and %d, respectively\n", x, y);
	printf("Note that: the value of x is arithmetically changed on each line\n");
	printf("x += y is equal to %d\n", x+=y);
	printf("x -= y is equal to %d\n", x-=y);
	printf("x *= y is equal to %d\n", x*=y);
	printf("x /= y is equal to %d\n", x/=y);
	printf("x %%= y is equal to %d\n", x%=y);
	printf("x <<= y is equal to %d\n", x<<=y);
	printf("x >>= y is equal to %d\n", x>>=y);
	printf("x &= y is equal to %d\n", x^=y);
	printf("x ^= y is equal to %d\n", x&=y);
	printf("x |= y is equal to %d\n", x|=y);
}

int main () {
	
	int choice, x, y, z;
	printf("-----Welcome to C Programming-----\n");
	printf("You will learn about operators in C programming\n\n");
	printf("1 for Arithmetic Operator \n2 for Relational Operator\n");
	printf("3 for Logical Operator \n4 for Bitwise Operator\n");
	printf("5 for Assigment Operators\n\n");
	printf("Enter a number: ");
	scanf("%d", &choice);
	
	while (choice > 5 || choice < 0) {
		printf("Please enter only 1-5: ");
		scanf("%d", &choice);
	}
	
	if (choice == 4) {
		printf("Warning! For this operator, your value should only be between 0 and 255\n");
	}
	
	printf("input value for x and y to either compute future calculations or make comparisons\n");
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);
	
	switch (choice) {
		case 1:
			arithmetic(x, y);
			break;
		case 2:
			relation(x, y);
			break;
		case 3:
			printf("For this operator, you need addictional value\n");
			printf("c = ");
			scanf("%d", &z);
			logical(x, y, z);
			break;
		case 4:
			bitwise(x, y);
			break;
		case 5:
			assignment(x, y);
			break;
	}
	char y_n;
	printf("Do you want to learn more?\n");
	printf("Enter only y or n: ");
	scanf(" %c", &y_n);
	
	while (y_n != 'y' && y_n != 'n') {
		printf("only enter y or n: ");
		scanf(" %c", &y_n);
		if (y_n == 'y' || y_n == 'n') {
			break;
		}
	}
	
	if (y_n == 'y') {
		printf("\n\n");
		main();
	} else {
		printf("---Thank you see you next time---");
	}
	
}
