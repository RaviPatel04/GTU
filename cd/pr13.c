// #include <stdio.h>
// #include <stdlib.h> // Include stdlib.h for malloc
// #include <string.h>

// char *input;
// int i = 0;
// char lasthandle[6], stack[50], handles[][5] = {")E(", "E*E", "E+E", "i", "E^E"}; // (E) becomes )E( when pushed to stack

// int top = 0, l;
// char prec[9][9] = {
//     /*input*/
//     /*stack    +    -   *   /   ^   i   (   )   $  */
//     /*  + */ '>',
//     '>',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '>',
//     '>',
//     /*  - */ '>',
//     '>',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '>',
//     '>',
//     /*  * */ '>',
//     '>',
//     '>',
//     '>',
//     '<',
//     '<',
//     '<',
//     '>',
//     '>',
//     /*  / */ '>',
//     '>',
//     '>',
//     '>',
//     '<',
//     '<',
//     '<',
//     '>',
//     '>',
//     /*  ^ */ '>',
//     '>',
//     '>',
//     '>',
//     '<',
//     '<',
//     '<',
//     '>',
//     '>',
//     /*  i */ '>',
//     '>',
//     '>',
//     '>',
//     '>',
//     'e',
//     'e',
//     '>',
//     '>',
//     /*  ( */ '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '>',
//     'e',
//     /*  ) */ '>',
//     '>',
//     '>',
//     '>',
//     '>',
//     'e',
//     'e',
//     '>',
//     '>',
//     /*  $ */ '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '<',
//     '>',
// };

// int getindex(char c) {
//     switch (c) {
//         case '+': return 0;
//         case '-': return 1;
//         case '*': return 2;
//         case '/': return 3;
//         case '^': return 4;
//         case 'i': return 5;
//         case '(': return 6;
//         case ')': return 7;
//         case '$': return 8;
//     }
// }

// int shift() {
//     stack[++top] = *(input + i++);
//     stack[top + 1] = '\0';
// }

// int reduce() {
//     int i, len, found, t;
//     for (i = 0; i < 5; i++) { // selecting handles
//         len = strlen(handles[i]);
//         if (stack[top] == handles[i][0] && top + 1 >= len) {
//             found = 1;
//             for (t = 0; t < len; t++) {
//                 if (stack[top - t] != handles[i][t]) {
//                     found = 0;
//                     break;
//                 }
//             }
//             if (found == 1) {
//                 stack[top - t + 1] = 'E';
//                 top = top - t + 1;
//                 strcpy(lasthandle, handles[i]);
//                 stack[top + 1] = '\0';
//                 return 1; // successful reduction
//             }
//         }
//     }
//     return 0;
// }

// void dispstack() {
//     for (int j = 0; j <= top; j++)
//         printf("%c", stack[j]);
// }

// void dispinput() {
//     for (int j = i; j < l; j++)
//         printf("%c", *(input + j));
// }

// int main() {
//     input = (char *)malloc(50 * sizeof(char)); // Allocate memory for input
//     printf("\nEnter the string\n");
//     scanf("%s", input);
//     input = strcat(input, "$");
//     l = strlen(input);
//     strcpy(stack, "$");
//     printf("\nSTACK\t\tINPUT\t\tACTION");

//     while (i <= l) {
//         shift();
//         printf("\n");
//         dispstack();
//         printf("\t\t");
//         dispinput();
//         printf("\t\tShift");

//         if (prec[getindex(stack[top])][getindex(input[i])] == '>') {
//             while (reduce()) {
//                 printf("\n");
//                 dispstack();
//                 printf("\t\t");
//                 dispinput();
//                 printf("\t\tReduced: E->%s", lasthandle);
//             }
//         }
//     }

//     if (strcmp(stack, "$E$") == 0)
//         printf("\nAccepted;");
//     else
//         printf("\nNot Accepted;");

//     free(input); // Free the allocated memory
//     return 0;
// }













// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX 20

// char grammar[MAX][MAX];
// char terminals[MAX];
// char precedenceTable[MAX][MAX];
// int numProductions;
// int numTerminals;

// void findTerminals();
// void buildPrecedenceTable();
// void displayPrecedenceTable();
// int getTerminalIndex(char symbol);
// void parseInput(char input[]);

// int main() {
//     int i;
//     printf("Enter the number of productions: ");
//     scanf("%d", &numProductions);
//     getchar(); // Consume newline

//     printf("Enter the productions (e.g., E=E+T):\n");
//     for (i = 0; i < numProductions; i++) {
//         fgets(grammar[i], MAX, stdin);
//         grammar[i][strcspn(grammar[i], "\n")] = 0; // Remove newline
//     }

//     findTerminals();
//     buildPrecedenceTable();
//     displayPrecedenceTable();

//     char input[MAX];
//     printf("Enter the input string to parse (end with $): ");
//     scanf("%s", input);
//     parseInput(input);

//     return 0;
// }

// void findTerminals() {
//     int i, j;
//     numTerminals = 0;
//     for (i = 0; i < numProductions; i++) {
//         for (j = 2; j < strlen(grammar[i]); j++) {
//             if (!isupper(grammar[i][j]) && grammar[i][j] != '=' &&
//                 strchr(terminals, grammar[i][j]) == NULL) {
//                 terminals[numTerminals++] = grammar[i][j];
//             }
//         }
//     }
//     terminals[numTerminals++] = '$';
//     terminals[numTerminals] = '\0';
// }

// void buildPrecedenceTable() {
//     int i, j;
//     for (i = 0; i < numTerminals; i++) {
//         for (j = 0; j < numTerminals; j++) {
//             precedenceTable[i][j] = ' ';
//         }
//     }

//     int plusIndex = getTerminalIndex('+');
//     int iIndex = getTerminalIndex('i');
//     int dollarIndex = getTerminalIndex('$');

//     if (plusIndex != -1 && iIndex != -1) {
//         precedenceTable[plusIndex][iIndex] = '<';
//         precedenceTable[iIndex][plusIndex] = '>';
//     }

//     if (iIndex != -1 && dollarIndex != -1) {
//         precedenceTable[iIndex][dollarIndex] = '>';
//     }

//     if (plusIndex != -1 && dollarIndex != -1) {
//         precedenceTable[plusIndex][dollarIndex] = '>';
//         precedenceTable[dollarIndex][plusIndex] = '<';
//     }

//     precedenceTable[dollarIndex][iIndex] = '<';
//     precedenceTable[dollarIndex][dollarIndex] = '=';
// }

// void displayPrecedenceTable() {
//     int i, j;
//     printf("\nPrecedence Table:\n");
//     printf("  ");
//     for (i = 0; i < numTerminals; i++) {
//         printf("%c ", terminals[i]);
//     }
//     printf("\n");
//     for (i = 0; i < numTerminals; i++) {
//         printf("%c ", terminals[i]);
//         for (j = 0; j < numTerminals; j++) {
//             printf("%c ", precedenceTable[i][j]);
//         }
//         printf("\n");
//     }
// }

// int getTerminalIndex(char symbol) {
//     for (int i = 0; i < numTerminals; i++) {
//         if (terminals[i] == symbol) {
//             return i;
//         }
//     }
//     return -1;
// }

// void parseInput(char input[]) {
//     char stack[MAX] = {0};
//     int top = -1;
//     int i = 0;
//     stack[++top] = '$';
//     stack[top + 1] = '\0';

//     printf("\nParsing Process:\n");
//     printf("Stack\t\tInput\t\tAction\n");

//     while (1) {
//         printf("%-15s\t%-15s\t", stack, input + i);

//         int stackTopIndex = getTerminalIndex(stack[top]);
//         int inputIndex = getTerminalIndex(input[i]);

//         if (stackTopIndex == -1 || inputIndex == -1) {
//             printf("Error: Invalid input or stack symbol\n");
//             return;
//         }

//         char relation = precedenceTable[stackTopIndex][inputIndex];

//         if (relation == '<' || relation == '=') {
//             stack[++top] = input[i++];
//             stack[top + 1] = '\0';
//             printf("Shift\n");
//         } else if (relation == '>') {
//             do {
//                 top--;
//             } while (top > 0 && precedenceTable[getTerminalIndex(stack[top])][getTerminalIndex(stack[top + 1])] != '<');
//             stack[top + 1] = '\0';
//             printf("Reduce\n");
//         } else {
//             printf("Error: No relation found\n");
//             return;
//         }

//         if (stack[top] == '$' && input[i] == '$') {
//             printf("Accepted\n");
//             break;
//         }
//     }
// }








#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char grammar[MAX][MAX]; // Grammar rules
char terminals[MAX];    // List of terminals
char precedenceTable[MAX][MAX]; // Precedence table
int numProductions;     // Number of grammar productions
int numTerminals;       // Number of terminals

void findTerminals();   // Function to find terminals
void buildPrecedenceTable(); // Function to build the precedence table
void displayPrecedenceTable(); // Function to display the precedence table
int getTerminalIndex(char symbol); // Get index of terminal
void parseInput(char input[]); // Function to parse input using precedence table

int main() {
    int i;
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // Consume newline

    printf("Enter the productions (e.g., E=E+T):\n");
    for (i = 0; i < numProductions; i++) {
        fgets(grammar[i], MAX, stdin);
        grammar[i][strcspn(grammar[i], "\n")] = 0; // Remove newline
    }

    // Identify the terminals and build the precedence table
    findTerminals();
    buildPrecedenceTable();
    displayPrecedenceTable();

    char input[MAX];
    printf("Enter the input string to parse (end with $): ");
    scanf("%s", input);
    parseInput(input); // Parse the input string

    return 0;
}

void findTerminals() {
    int i, j;
    numTerminals = 0;
    for (i = 0; i < numProductions; i++) {
        for (j = 2; j < strlen(grammar[i]); j++) { // Start from index 2 to skip the non-terminal and '='
            if (!isupper(grammar[i][j]) && grammar[i][j] != '=' && strchr(terminals, grammar[i][j]) == NULL) {
                terminals[numTerminals++] = grammar[i][j];
            }
        }
    }
    terminals[numTerminals++] = '$'; // Add the end marker '$'
    terminals[numTerminals] = '\0';
}

void buildPrecedenceTable() {
    int i, j;
    for (i = 0; i < numTerminals; i++) {
        for (j = 0; j < numTerminals; j++) {
            precedenceTable[i][j] = ' '; // Initialize table with spaces
        }
    }

    // Manually setting precedence based on the grammar rules
    int plusIndex = getTerminalIndex('+');
    int multIndex = getTerminalIndex('*');
    int iIndex = getTerminalIndex('i');
    int dollarIndex = getTerminalIndex('$');

    // Set precedence for '+' operator
    if (plusIndex != -1 && iIndex != -1) {
        precedenceTable[plusIndex][iIndex] = '<';
        precedenceTable[iIndex][plusIndex] = '>';
    }
    if (plusIndex != -1 && multIndex != -1) {
        precedenceTable[plusIndex][multIndex] = '<';
        precedenceTable[multIndex][plusIndex] = '>';
    }

    // Set precedence for '*' operator
    if (multIndex != -1 && iIndex != -1) {
        precedenceTable[multIndex][iIndex] = '<';
        precedenceTable[iIndex][multIndex] = '>';
    }

    // Set precedence for 'i' (input terminal) with '$'
    if (iIndex != -1 && dollarIndex != -1) {
        precedenceTable[iIndex][dollarIndex] = '>';
    }

    // Set precedence for '$' (end marker)
    if (dollarIndex != -1) {
        precedenceTable[dollarIndex][iIndex] = '<';
        if (plusIndex != -1) precedenceTable[dollarIndex][plusIndex] = '<';
        if (multIndex != -1) precedenceTable[dollarIndex][multIndex] = '<';
        precedenceTable[dollarIndex][dollarIndex] = '=';
    }

    // Operators with '$'
    if (plusIndex != -1) precedenceTable[plusIndex][dollarIndex] = '>';
    if (multIndex != -1) precedenceTable[multIndex][dollarIndex] = '>';
}

void displayPrecedenceTable() {
    int i, j;
    printf("\nPrecedence Table:\n");
    printf("  ");
    for (i = 0; i < numTerminals; i++) {
        printf("%c ", terminals[i]);
    }
    printf("\n");
    for (i = 0; i < numTerminals; i++) {
        printf("%c ", terminals[i]);
        for (j = 0; j < numTerminals; j++) {
            printf("%c ", precedenceTable[i][j]);
        }
        printf("\n");
    }
}

int getTerminalIndex(char symbol) {
    for (int i = 0; i < numTerminals; i++) {
        if (terminals[i] == symbol) {
            return i;
        }
    }
    return -1;
}

void parseInput(char input[]) {
    char stack[MAX] = {0};
    int top = -1;
    int i = 0;
    stack[++top] = '$'; // Initialize stack with '$'
    stack[top + 1] = '\0';

    printf("\nParsing Process:\n");
    printf("Stack\t\tInput\t\tAction\n");

    while (1) {
        printf("%-15s\t%-15s\t", stack, input + i);

        int stackTopIndex = getTerminalIndex(stack[top]);
        int inputIndex = getTerminalIndex(input[i]);

        if (stackTopIndex == -1 || inputIndex == -1) {
            printf("Error: Invalid input or stack symbol\n");
            return;
        }

        char relation = precedenceTable[stackTopIndex][inputIndex];

        if (relation == '<' || relation == '=') {
            stack[++top] = input[i++]; // Shift the input to stack
            stack[top + 1] = '\0';
            printf("Shift\n");
        } else if (relation == '>') {
            do {
                top--; // Pop the stack during reduction
            } while (top > 0 && precedenceTable[getTerminalIndex(stack[top])][getTerminalIndex(stack[top + 1])] != '<');
            stack[top + 1] = '\0';
            printf("Reduce\n");
        } else {
            printf("Error: No relation found\n");
            return;
        }

        if (stack[top] == '$' && input[i] == '$') {
            printf("Accepted\n");
            break;
        }
    }
}
