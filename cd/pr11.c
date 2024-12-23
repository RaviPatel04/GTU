#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void followfirst(char, int, int);
void findfirst(char, int, int);
void follow(char c);

int count, n = 0;
char calc_first[10][100];
char calc_follow[10][100];
int m = 0;
char production[10][10], first[10];
char f[10];
int k;
char ck;
int e;

int main() {
    int jm = 0;
    int km = 0;
    int i, choice;
    char c, ch;

    printf("How many productions? : ");
    scanf("%d", &count);
    printf("\nEnter %d productions in form A=B where A and B are grammar symbols:\n\n", count);
    
    // Read productions
    for (i = 0; i < count; i++) {
        scanf("%s%c", production[i], &ch);
    }

    // Calculate FIRST sets
    int kay;
    char done[count];
    int ptr = -1;

    for (k = 0; k < count; k++) {
        memset(calc_first[k], '!', sizeof(calc_first[k]));
    }

    for (k = 0; k < count; k++) {
        c = production[k][0];
        int point2 = 0;
        int found = 0;
        
        for (kay = 0; kay <= ptr; kay++) {
            if (c == done[kay]) {
                found = 1;
                break;
            }
        }

        if (found) continue;

        findfirst(c, 0, 0);
        done[++ptr] = c;
        
        printf("\nFirst(%c) = { ", c);
        calc_first[jm][point2++] = c;
        
        for (i = 0; i < n; i++) {
            int exists = 0;
            for (kay = 0; kay < point2; kay++) {
                if (first[i] == calc_first[jm][kay]) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                printf("%c, ", first[i]);
                calc_first[jm][point2++] = first[i];
            }
        }
        printf("}\n");
        jm = n;
    }

    printf("\n");

    // Calculate FOLLOW sets
    char donee[count];
    ptr = -1;
    
    for (k = 0; k < count; k++) {
        memset(calc_follow[k], '!', sizeof(calc_follow[k]));
    }

    for (e = 0; e < count; e++) {
        ck = production[e][0];
        int point2 = 0;
        int found = 0;
        
        for (kay = 0; kay <= ptr; kay++) {
            if (ck == donee[kay]) {
                found = 1;
                break;
            }
        }

        if (found) continue;

        follow(ck);
        donee[++ptr] = ck;
        
        printf("Follow(%c) = { ", ck);
        calc_follow[m][point2++] = ck;

        for (i = 0; i < m; i++) {
            int exists = 0;
            for (kay = 0; kay < point2; kay++) {
                if (f[i] == calc_follow[m][kay]) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                printf("%c, ", f[i]);
                calc_follow[m][point2++] = f[i];
            }
        }
        printf("}\n\n");
        km = m;
        m++;
    }

    // Identifying terminals
    char ter[10];
    memset(ter, '!', sizeof(ter));
    int sid = 0;

    for (k = 0; k < count; k++) {
        for (kay = 0; kay < strlen(production[k]); kay++) {
            if (!isupper(production[k][kay]) && production[k][kay] != '#' && production[k][kay] != '=' && production[k][kay] != '\0') {
                int exists = 0;
                for (int ap = 0; ap < sid; ap++) {
                    if (production[k][kay] == ter[ap]) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    ter[sid++] = production[k][kay];
                }
            }
        }
    }
    ter[sid++] = '$'; // End of input symbol

    // Print LL(1) Parsing Table header
    printf("\nLL(1) Parsing Table for the above grammar:\n");
    printf("=============================================================\n");
    printf("\t\t\t\t");
    for (int ap = 0; ap < sid; ap++) {
        printf("%c\t", ter[ap]);
    }
    printf("\n=============================================================\n");

    // Constructing the parsing table
    char table[10][10]; // LL(1) parsing table
    memset(table, '!', sizeof(table));

    for (int prod = 0; prod < count; prod++) {
        char lhs = production[prod][0];
        for (int j = 2; j < strlen(production[prod]); j++) {
            char rhs = production[prod][j];
            for (int t = 0; t < sid; t++) {
                if (rhs == ter[t]) {
                    table[prod][t] = lhs;
                }
            }
        }
    }

    // Print LL(1) Parsing Table
    for (int i = 0; i < count; i++) {
        printf("%c\t", production[i][0]);
        for (int j = 0; j < sid; j++) {
            if (table[i][j] != '!') {
                printf("%c\t", table[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }

    // Input string and parsing
    printf("\nPlease enter the desired INPUT STRING = ");
    char input[100];
    scanf("%s%c", input, &ch);
    printf("\nStack\t\t\tInput\t\t\tAction\n");
    printf("=============================================================\n");

    // Parsing logic
    char stack[100];
    int top = -1;
    stack[++top] = '$'; // End marker
    stack[++top] = production[0][0]; // Start symbol

    int pos = 0; // Input position

    while (top != -1) {
        char topStack = stack[top];
        char currentInput = input[pos];

        if (topStack == currentInput) {
            printf("%s\t\t%s\t\tMatch %c\n", stack, input, currentInput);
            top--;
            pos++;
        } else if (isupper(topStack)) {
            // Find production rule
            int productionIndex = -1;
            for (int i = 0; i < count; i++) {
                if (production[i][0] == topStack) {
                    for (int j = 2; j < strlen(production[i]); j++) {
                        if (production[i][j] == currentInput) {
                            productionIndex = i;
                            break;
                        }
                    }
                    if (productionIndex != -1) break;
                }
            }

            if (productionIndex != -1) {
                printf("%s\t\t%s\t\tApply %s\n", stack, input, production[productionIndex]);
                top--; // Pop the non-terminal from the stack
                for (int j = strlen(production[productionIndex]) - 1; j >= 2; j--) { // Push the production onto the stack
                    if (production[productionIndex][j] != '#') {
                        stack[++top] = production[productionIndex][j];
                    }
                }
            } else {
                printf("Error: no production found for %c\n", topStack);
                break;
            }
        } else {
            printf("Error: unexpected symbol %c in stack\n", topStack);
            break;
        }
    }

    return 0;
}

void follow(char c) {
    int i, j;
    if (production[0][0] == c) {
        f[m++] = '$';
    }
    for (i = 0; i < count; i++) {
        for (j = 2; j < strlen(production[i]); j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0') {
                    followfirst(production[i][j + 1], i, (j + 2));
                }
                if (production[i][j + 1] == '\0' && c != production[i][0]) {
                    follow(production[i][0]);
                }
            }
        }
    }
}

void findfirst(char c, int q1, int q2) {
    int j;
    if (!isupper(c)) {
        first[n++] = c;
    }
    for (j = 0; j < count; j++) {
        if (production[j][0] == c) {
            if (production[j][2] == '#') {
                first[n++] = '#';
            }
            if (isupper(production[j][2])) {
                findfirst(production[j][2], j, 2);
            } else {
                first[n++] = production[j][2];
            }
        }
    }
}

void followfirst(char c, int i, int j) {
    for (int k = 0; k < count; k++) {
        if (production[k][0] == c) {
            if (production[k][2] != '\0') {
                if (islower(production[k][2])) {
                    f[m++] = production[k][2];
                } else {
                    followfirst(production[k][2], k, j);
                }
            }
        }
    }
}
