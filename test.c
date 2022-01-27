#include <stdio.h>
#include <math.h>

/* 
    A programme to calculate an area of 4 2D shapes, such as circle, equilateral triangle, trapezium and pentagon, based on user input.
*/

// function declaration
int is_in_list(int arr[], int x);
float circle();
float trapezium();
float triangle();
float pentagon();


int main() {
    char choice;
    int shape_list[] = {1, 2, 3, 4};
    // welcome message
    printf("Welcome to Area Calculator\n\n");

    while (1) {
        int shape;
        printf("What kind of shape would you like?\n Please type\n '1' for circle\n '2' for equilateral triangle\n '3' for trapezium\n '4' for pentagon\n");
        scanf(" %d", &shape);

        // check if the input is out of range
        while (!is_in_list(shape_list, shape)) {
            printf("The number you just entered is out of range\n");
            printf("Only enter a number between 1-4\n");
            printf("Please Enter again: \n");
            scanf(" %d", &shape);
        }

        // work out an area depending on the shape
        switch (shape) {
            case 1:
                printf("The area is %f\n\n", circle());
                break;
            case 2:
                printf("The area is %f\n\n", triangle());
                break;
            case 3:
                printf("The area is %f\n\n", trapezium());
                break;
            case 4:
                printf("The area is %f\n\n", pentagon());
                break;
        }

        // check if an user want to continue doing this
        printf("Do want to continue working out area? (y or n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            continue;
        } else {
            printf("\nAlright See Yah Soon!!!");
            break;
        }
    }
    return 0;
}

// function to check if a number is in an array of number
int is_in_list(int arr[], int x) {  
    for (int i=0;i<4;i++) {
        if (arr[i] == x) {
            return 1;
            break;
        }
    }
    return 0;
}

// function to calculate an area of each shape

float circle()  {
    // r means redius of a circle
    float r;
    printf("Enter the size of radius: \n");
    scanf("%f", &r);
    float pi = 22.0/7;
    return pi*pow(r,2);
}

float trapezium() {
    // b1, b2 and h represent base 1, base 2 and height, respectively.
    float b1, b2, h;
    printf("Enter base 1: \n");
    scanf("%f", &b1);
    printf("Enter base 2: \n");
    scanf("%f", &b2);
    printf("Enter height: \n");
    scanf("%f", &h);

    return ((b1 + b2)/2)*h;
}

float triangle() {
    // s represents length of side
    // h represents height
    float s;
    printf("Enter the length of side: \n");
    scanf("%f", &s);
    float h = sqrt(3)*(s/2); 
    return (s*h)/2;
}

float pentagon() {
    // s means length of side
    float s;
    printf("Enter the length of side: \n");
    scanf("%f", &s);
    return (0.25)*(sqrt(5*(5+2*sqrt(5))))*pow(s, 2);
}
