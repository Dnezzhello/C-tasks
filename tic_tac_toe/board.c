#include <stdio.h>

void board (char *arr) {
    printf("    |   |   \n");
    printf("  %c | %c | %c \n", arr[6], arr[7], arr[8]);
    printf("    |   |   \n");

    printf(" -----------\n");

    printf("    |   |   \n");
    printf("  %c | %c | %c \n", arr[3], arr[4], arr[5]);
    printf("    |   |   \n");

    printf(" -----------\n");

    printf("    |   |   \n");
    printf("  %c | %c | %c \n", arr[0], arr[1], arr[2]);
    printf("    |   |   \n");
}
