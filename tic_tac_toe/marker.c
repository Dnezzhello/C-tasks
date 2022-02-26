#include <stdio.h>

extern char current_marker;

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
