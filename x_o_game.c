#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static char current_marker, first_marker;

void board (char *arr) {
    printf("\n");

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

    printf("\n");
}

void who_is_next (int turns, char first_marker) {
    if (first_marker == 'x') {
            if (turns % 2 == 0) {
                current_marker = 'o';
            } else {
                current_marker = first_marker;
            }
            
        }

    if (first_marker == 'o') {
        if (turns % 2 == 0) {
            current_marker = 'x';
        } else {
            current_marker = first_marker;
        }
        
    }
}

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

int is_in_list (int arr[], int position) {
    for (int i=0;i<9;i++) {
        if (arr[i] == position) {
            return 1;
        }
    }
    return 0;
}

int main () {
    char X_or_O;
    int turns = 1, position, position_tracking[9];
    char tracking_arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for (int i=0;i<9;i++) {
        position_tracking[i] = 0;
    }

    printf("Who wants to go first?\n");
    scanf(" %c", &X_or_O);
    
    if (X_or_O == 'x') {
        current_marker = 'x';
        first_marker = 'x';
        printf("The player with 'x' mark goes first\n");
    } else {
        current_marker = 'o';
        first_marker = 'o';
        printf("The player with 'o' mark goes first\n");
    }
    // welcome message
    printf("\nLet's start our game\n");
    board(tracking_arr);

    // main game player
    while (turns <= 9 ) {

        // decide who will go next and where the marker will be placed
        who_is_next(turns, first_marker);
        printf("Where do you want to put your '%c': ", current_marker);
        scanf(" %d", &position);

        // check whether or not the recent input has already been used
        while (is_in_list(position_tracking, position)) {
            printf("That position is already used. Enter a new position: ");
            scanf("%d", &position);
        }
        position_tracking[position-1] = position;

        // update board game
        tracking_arr[position-1] = current_marker;
        board(tracking_arr);
        // proceed to the next turn
        turns++;

        if (have_a_winner(tracking_arr)) {
            printf("\nwinner!!");
            break;
        }

        // nothing happens then a draw happens
        if (turns == 9) {
            printf("\nDraw!!\n");
        }

    }
    

    return 0;
}