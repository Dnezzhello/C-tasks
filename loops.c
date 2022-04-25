#include <stdio.h>
#include <math.h>

// homework using loops

int prime_checker();

int main() {
	// a programme to check whether an input is prime or not

	int n;
	char choice;

	printf("--- WELCOME TO PRIME NUMBER CHECKER ---\n\n");
	while (1) {

		printf("Enter a whole number: ");
		scanf("%d", &n);

		if (prime_checker(n)) {
			goto is_prime;
		} else {
			printf("%d is not prime!\n", n);
			goto continue_executing;
		}

		// goto 
		is_prime:
			printf("%d is prime!\n", n);

		continue_executing:
			do {
				printf("Do you want to continue?\n");
				printf("please type only 'y' for yes or 'n' for no: ");
				scanf(" %c", &choice);
				
				if (choice == 'y' || choice == 'n') {
					break;
				} 

			} while (choice != 'y' || choice != 'n');

			if (choice == 'y') {
				printf("\n\n");
				continue;
			} else {
				printf("GOOD BYE");
				break;
			} 
		}

	return 0;
}

int prime_checker(int n) {

	if (n <= 1) return 0;

	for (int i=2;i<=sqrt(n);i++) {
		if (n % i == 0) {
			return 0;
			break;
		} 
	}
	return 1;
}
