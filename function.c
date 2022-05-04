#include <stdio.h>

// Souphaxay Naovalath 1CS1

float addition(float, float);
float subtraction(float, float);
float multiplication(float, float);
float division(float, float);

int main() {

	char operator, choice;
	float operand1, operand2;
	// welcome message
	printf("--- Welcome to a simple calculator ---\n\n");
	// get an operator
	printf("Enter an operator to do a calculation (+ - * /)\n");
	printf("Input: ");
	scanf(" %c", &operator);
	// get two operands
	printf("operand 1 : ");
	scanf(" %f", &operand1);
	printf("operand 2 : ");
	scanf(" %f", &operand2);

	switch(operator) {
		case '+':
			printf("%.2f + %.2f = %.2f\n", operand1, operand2, addition(operand1, operand2));
			break;
		case '-':
			printf("%.2f - %.2f = %.2f\n", operand1, operand2, subtraction(operand1, operand2));
			break;
		case '*':
			printf("%.2f * %.2f = %.2f\n", operand1, operand2, multiplication(operand1, operand2));
			break;
		case '/':
			printf("%.2f / %.2f = %.9f\n", operand1, operand2, division(operand1, operand2));
			break;
		default:
			printf("Error Invalid Operator!\n");
			main();
	}

	printf("Do you want to continue? (y or n): ");
	scanf(" %c", &choice);
	if (choice == 'y') {
		main();
	} else if (choice == 'n') {
		printf("See yah");
	} else {
		printf("ERROR! PLEASE RESTART THIS PROGRAMME");
	}
	return 0;
}

float addition(float x, float y) {
	return x + y;
};
float subtraction(float x, float y) {
	return x-y;
};
float multiplication(float x, float y) {
	return x*y;
};
float division(float x, float y) {
	return x/y;
};
