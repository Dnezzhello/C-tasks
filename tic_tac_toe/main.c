#include <stdio.h>

/* This programme was designed and written by a newbie in C programmig, so please bear with known but unsolved bugs in my code*/

extern void board(char *arr);
void who_is_next(int turns, char first_marker);
extern int have_a_winner(char arr[9]);
extern int is_used_position(int arr[], int position);

char current_marker; // global variable

int main () {

    // a loop to control this game
    while (1) {
        char x_or_o, user_choice,tracking_arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char first_marker;
	int turns = 1, position, position_tracking[9];

        // to somehow prevent unexpected error
	for (int i=0;i<9;i++) {
	    position_tracking[i] = 0;
	}

        // a message to tell players that a programme has started
        printf("Welcome to Tic-Tac-Toe game\n");
        printf("Who wants to go first? (x or o): ");
        scanf(" %c", &x_or_o);

        // user can only input x or o
	    while (x_or_o != 'x' && x_or_o != 'o') {
	        printf("Please only type x or o: ");
		scanf(" %c", &x_or_o);
		if (x_or_o == 'x' || x_or_o == 'o') {
		    break;
		}
	    }

        // display who will go first based on previous input
	    if (x_or_o == 'x') {
	        current_marker = 'x';
	        first_marker = 'x';
	        printf("The player with 'x' mark goes first\n");
	    } else {
	        current_marker = 'o';
	        first_marker = 'o';
	        printf("The player with 'o' mark goes first\n");
	    }

	    // a message to signify the game has started
	    printf("\nLet's start our game\n");
	    board(tracking_arr);

        // loops until we have a winner or a draw happens
	    while (turns <= 9 ) {
	
	        // decide who will go next and where the marker will be placed
	        who_is_next(turns, first_marker);
	        printf("Where do you want to place your '%c': ", current_marker);
	        scanf(" %d", &position);
	
	        // check whether or not the recent input will duplicate previous ones
	        while (is_used_position(position_tracking, position)) {
	            printf("That position is already used. Enter a new position: ");
	            scanf(" %d", &position);
	        }
	        position_tracking[position-1] = position;
	
	        // update board game
	        tracking_arr[position-1] = current_marker;
	        board(tracking_arr);
	        
		    // check each turn if or not we have a winner and if a draw happens
	        if (have_a_winner(tracking_arr)) {
	            printf("\nWe have a winner!!!!!!\n");
	      		break;
	        } else if (turns == 9) {
	            printf("\nDraw!!\n");
	            break;
	        } else {}
	        
	        // proceed to the next turn
	        turns++;
        }

        // prompt an user to tell us if or not they want to continue
		printf("Do you want to continue playing? (y or n): ");
		scanf(" %c", &user_choice);
		while (user_choice != 'y' && user_choice != 'n') {
		    printf("Please only type y or n: ");
		    scanf(" %c", &user_choice);
		    if (user_choice == 'y' || user_choice == 'n') {
		        break;
		    }
		}

		if (user_choice == 'n') {
	    	    break;
		} else {
		    continue;
		}	
    }
    return 0;
}
