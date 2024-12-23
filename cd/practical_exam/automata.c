//Finite Automata and String Validation

#include <stdio.h>
#include <string.h>

// Function to check if a string ends with "ab"
int finite_automata(const char *string) {
    int state = 0; // Start state
    for (int i = 0; string[i] != '\0'; i++) {
        char ch = string[i];
        if (state == 0) {
            state = (ch == 'a') ? 1 : 0;
        } else if (state == 1) {
            state = (ch == 'b') ? 2 : 1;
        } else if (state == 2) {
            state = (ch == 'a') ? 1 : 0;
        }
    }
    return state == 2; // Accept state
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    if (finite_automata(string)) {
        printf("String is valid.\n");
    } else {
        printf("String is invalid.\n");
    }
    return 0;
}
