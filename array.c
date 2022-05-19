#include <stdio.h>
#include <string.h>

int main()
{
	char std_name[20][15];
	int i;

	printf("--- A list of students'name of 1CS1 Class in the academic year of 2021-2022 ---\n\n");

	printf("You are required to type each student's first name in English\n");
	printf("quit the programme by typing 'stop'\n\n");
	while (1) {
		printf("Student %d : ", i+1);
		scanf(" %s", std_name+i);
		if (!strcmp(*(std_name+i), "stop")) break;
		i++;
	}
	printf("\n\n --------------------------------------------------- \n\n");
	for (int j=0;j<i;j++) {
		printf("Student %d : %s\n", j+1, std_name[j]);
	}

	return 0;
}
