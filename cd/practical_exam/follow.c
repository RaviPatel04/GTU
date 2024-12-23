//Finding "Follow" Set

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_GRAMMAR 100
#define MAX_SYMBOLS 10

char grammar[MAX_GRAMMAR][MAX_SYMBOLS];
int num_grammar = 0;

// Function to compute Follow set
void compute_follow(char non_terminal, char follow_set[]) {
    int index = 0;
    if (non_terminal == grammar[0][0]) { // Start symbol
        follow_set[index++] = '$';
    }

    for (int i = 0; i < num_grammar; i++) {
        for (int j = 3; grammar[i][j] != '\0'; j++) {
            if (grammar[i][j] == non_terminal) {
                if (grammar[i][j + 1] != '\0') { // Next symbol exists
                    if (islower(grammar[i][j + 1])) { // Terminal
                        follow_set[index++] = grammar[i][j + 1];
                    } else if (isupper(grammar[i][j + 1])) { // Non-terminal
                        char temp_set[MAX_SYMBOLS];
                        compute_follow(grammar[i][j + 1], temp_set);
                        for (int k = 0; temp_set[k] != '\0'; k++) {
                            if (temp_set[k] != '#') { // Exclude epsilon
                                follow_set[index++] = temp_set[k];
                            }
                        }
                    }
                } else { // Last symbol in the production
                    char temp_set[MAX_SYMBOLS];
                    compute_follow(grammar[i][0], temp_set);
                    for (int k = 0; temp_set[k] != '\0'; k++) {
                        follow_set[index++] = temp_set[k];
                    }
                }
            }
        }
    }
    follow_set[index] = '\0';
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
    char non_terminal, follow_set[MAX_SYMBOLS];

    printf("Enter the number of grammar rules: ");
    scanf("%d", &num_grammar);

    printf("Enter the grammar rules (e.g., S->aB):\n");
    for (int i = 0; i < num_grammar; i++) {
        scanf("%s", grammar[i]);
    }

    for (int i = 0; i < num_grammar; i++){
        printf("Enter the non-terminal symbol to compute Follow set: ");
        scanf(" %c", &non_terminal);

        // Compute Follow set
        compute_follow(non_terminal, follow_set);
        remove_duplicates(follow_set);
        printf("Follow(%c): { ", non_terminal);
        for (int i = 0; follow_set[i] != '\0'; i++) {
            printf("%c ", follow_set[i]);
        }
        printf("}\n");
    }

    return 0;
}
