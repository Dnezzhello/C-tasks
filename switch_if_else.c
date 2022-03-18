#include <stdio.h>

/*This simple code is only for showing how to use switch statement and if else in C*/

int main() {
	int score;
	char grade;
	char choice;
	printf("Input Score: ");
	scanf(" %d", &score);

	while (score < 0 || score > 100) {
		printf("only 0-100 please re-enter: ");
		scanf(" %d", &score);
	}
	
	if (score >= 80) {
		grade = 'A';
	} else if (score >= 70) {
		grade = 'B';
	} else if (score >= 60) {
		grade = 'C';
	} else if (score >= 50) {
		grade = 'D';
	} else {
		grade = 'F';
	}

	switch (grade){
		case 'A':
			printf("Grade is A\n");
			break;
		case 'B':
			printf("Grade is B\n");
			break;
		case 'C':
			printf("Grade is C\n");
			break;
		case 'D':
			printf("Grade is D\n");
			break;
		case 'F':
			printf("Grade is F\n");
			break;
	}
 
	printf("want to continue?(y or n): ");
	scanf(" %c", &choice);
	while (choice != 'y' && choice != 'n') {
		printf("Only enter y or n: ");
		scanf(" %c", &choice);
		if (choice == 'n' || choice == 'y') {break;}
	}
	if (choice == 'y') {
		main();
	} else {
		printf("Done!");
	}
	return 0;
}
