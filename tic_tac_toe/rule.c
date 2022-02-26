#include <stdio.h>

int have_a_winner (char arr[9]) {
    if (arr[0] == arr[1] && arr[0] == arr[2]) {
        return 1;
    } else if (arr[3] == arr[4] && arr[3] == arr[5]) {
        return 1;
    } else if (arr[6] == arr[7] && arr[6] == arr[8]) {
        return 1;
    } else if (arr[0] == arr[3] && arr[0] == arr[6]) {
        return 1;
    } else if (arr[1] == arr[4] && arr[1] == arr[7]) {
        return 1;
    } else if (arr[2] == arr[5] && arr[2] == arr[8]) {
        return 1;
    } else if (arr[2] == arr[4] && arr[2] == arr[6]) {
        return 1;
    } else if (arr[0] == arr[4] && arr[0] == arr[8]) {
        return 1;
    } else {
        return 0;
    }
}
