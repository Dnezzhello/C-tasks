#include <stdio.h>

int is_used_position (int arr[], int position) {
    for (int i=0;i<9;i++) {
        if (arr[i] == position) {
            return 1;
        }
    }
    return 0;
}
