#include <stdio.h>
#include <stdlib.h>

float sum(float *arr, int size);
float avg(float sum, int size);

int main() {
	float *arr;
	int n;

	printf("\n\n\n--// The programme to calculate sum and average \\--\n\n\n");
	printf("How many data do you want to input?\n");
	printf("Input: ");
	scanf("%d", &n);

	printf("\n\n--- Now you need to input your data into this programme ---\n\n");

	arr = (float*) malloc(n*sizeof(float));
	for (int i=0;i<n;i++) {
		printf("data %d : ", i+1);
		scanf("%f", &arr[i]);
	}

	free(arr);

	printf("\n\nThe sum and average of your data are %.2f and %.2f\n", sum(arr, n), avg(sum(arr, n), n));
	return 0;
}

float sum(float *arr, int size) {
	float sum = 0;
	for (int i=0;i<size;i++) {
		sum += *(arr+i);
	}
	return sum;
}

float avg(float sum, int size) {
	return sum/size;
}
