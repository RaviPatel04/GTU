//Finding "First" Set


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_GRAMMAR 100
#define MAX_SYMBOLS 10

char grammar[MAX_GRAMMAR][MAX_SYMBOLS];
int num_grammar = 0;

// Function to compute First set
void compute_first(char non_terminal, char first_set[]) {
    int index = 0;
    for (int i = 0; i < num_grammar; i++) {
        if (grammar[i][0] == non_terminal) { // Rule starts with the non-terminal
            for (int j = 3; grammar[i][j] != '\0'; j++) {
                if (islower(grammar[i][j])) { // Terminal
                    first_set[index++] = grammar[i][j];
                    break;
                } else if (isupper(grammar[i][j])) { // Non-terminal
                    char temp_set[MAX_SYMBOLS];
                    compute_first(grammar[i][j], temp_set);
                    for (int k = 0; temp_set[k] != '\0'; k++) {
                        first_set[index++] = temp_set[k];
                    }
                    break;
                }
            }
        }
    }
    first_set[index] = '\0';
}

// Utility function to remove duplicates from a set
void remove_duplicates(char set[]) {
    int len = strlen(set);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len;) {
            if (set[i] == set[j]) {
                for (int k = j; k < len - 1; k++) {
                    set[k] = set[k + 1];
                }
                len--;
            } else {
                j++;
            }
        }
    }
    set[len] = '\0';
}

int main() {
    char non_terminal, first_set[MAX_SYMBOLS];

    printf("Enter the number of grammar rules: ");
    scanf("%d", &num_grammar);

    printf("If you have grammar like S->aB|c then give seprately.\n");
    printf("Enter the grammar rules (e.g., S->aB):\n");
    for (int i = 0; i < num_grammar; i++) {
        scanf("%s", grammar[i]);
    }

    for (int i = 0; i < num_grammar; i++){

        printf("Enter the non-terminal symbol to compute First set: ");
        scanf(" %c", &non_terminal);

        // Compute First set
        compute_first(non_terminal, first_set);
        remove_duplicates(first_set);
        printf("First(%c): { ", non_terminal);
        for (int i = 0; first_set[i] != '\0'; i++) {
            printf("%c ", first_set[i]);
        }
        printf("}\n");
    }

    return 0;
}
