// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX 10
// #define EPSILON '#' // Use # to represent epsilon

// struct production {
//     char lhs;
//     char rhs[20];
// } prod[MAX];

// char followSets[MAX][20]; // To store Follow sets for each non-terminal
// int computedFollow[MAX];  // Flag to check if Follow has been computed for each non-terminal
// int n; // Number of productions

// void findFirst(char c, char* first);
// void addFollow(char* followSet, char c);
// void findFollow(char c);
// void initializeFollowSet(char* followSet);

// void findFirst(char c, char* first) {
//     int i, j;
//     for (i = 0; i < n; i++) {
//         if (prod[i].lhs == c) {
//             if (islower(prod[i].rhs[0])) {
//                 addFollow(first, prod[i].rhs[0]);
//             } else if (isupper(prod[i].rhs[0])) {
//                 findFirst(prod[i].rhs[0], first);
//             } else if (prod[i].rhs[0] == EPSILON) {
//                 addFollow(first, EPSILON);
//             }
//         }
//     }
// }

// void addFollow(char* followSet, char c) {
//     if (strchr(followSet, c) == NULL) {
//         size_t len = strlen(followSet);
//         followSet[len] = c;
//         followSet[len + 1] = '\0';
//     }
// }

// void findFollow(char c) {
//     int i, j;
//     char first[20];
//     if (computedFollow[c - 'A']) {
//         return;  // If Follow set has already been computed, skip
//     }

//     initializeFollowSet(followSets[c - 'A']); // Initialize the follow set

//     if (c == prod[0].lhs) {
//         addFollow(followSets[c - 'A'], '$');
//     }

//     for (i = 0; i < n; i++) {
//         for (j = 0; prod[i].rhs[j] != '\0'; j++) {
//             if (prod[i].rhs[j] == c) {
//                 if (prod[i].rhs[j + 1] != '\0') {
//                     memset(first, 0, sizeof(first));
//                     if (islower(prod[i].rhs[j + 1])) {
//                         addFollow(followSets[c - 'A'], prod[i].rhs[j + 1]);
//                     } else {
//                         findFirst(prod[i].rhs[j + 1], first);
//                         for (int k = 0; first[k] != '\0'; k++) {
//                             if (first[k] != EPSILON) {
//                                 addFollow(followSets[c - 'A'], first[k]);
//                             }
//                         }
//                         if (strchr(first, EPSILON)) {
//                             findFollow(prod[i].lhs); // Recursive call
//                             for (int k = 0; followSets[prod[i].lhs - 'A'][k] != '\0'; k++) {
//                                 addFollow(followSets[c - 'A'], followSets[prod[i].lhs - 'A'][k]);
//                             }
//                         }
//                     }
//                 }
//                 if (prod[i].rhs[j + 1] == '\0' && prod[i].lhs != c) {
//                     findFollow(prod[i].lhs);
//                     for (int k = 0; followSets[prod[i].lhs - 'A'][k] != '\0'; k++) {
//                         addFollow(followSets[c - 'A'], followSets[prod[i].lhs - 'A'][k]);
//                     }
//                 }
//             }
//         }
//     }

//     computedFollow[c - 'A'] = 1; // Mark follow as computed
// }

// void initializeFollowSet(char* followSet) {
//     followSet[0] = '\0'; // Empty the follow set
// }

// int main() {
//     int i;
//     char c;
//     printf("Enter number of productions: ");
//     scanf("%d", &n);
//     printf("Enter the productions in the form A=B (use capital letters for non-terminals and # for epsilon):\n");
//     for (i = 0; i < n; i++) {
//         printf("Production %d: ", i + 1);
//         char rhs[20];
//         scanf(" %c=%s", &prod[i].lhs, rhs);
//         if (strcmp(rhs, "#") == 0) {
//             prod[i].rhs[0] = EPSILON; // Set the first character of rhs to EPSILON
//             prod[i].rhs[1] = '\0';    // Null-terminate the string
//         } else {
//             strcpy(prod[i].rhs, rhs);
//         }
//     }

//     // Initialize computedFollow array
//     for (i = 0; i < MAX; i++) {
//         computedFollow[i] = 0;
//     }

//     // Calculate Follow sets for all non-terminals
//     for (i = 0; i < n; i++) {
//         c = prod[i].lhs;
//         if (!computedFollow[c - 'A']) {
//             findFollow(c);
//         }
//     }

//     // Print Follow sets for unique non-terminals
//     int printed[26] = {0}; // Array to keep track of printed non-terminals
//     for (i = 0; i < n; i++) {
//         c = prod[i].lhs;
//         if (computedFollow[c - 'A'] && !printed[c - 'A']) {
//             printf("Follow(%c) = { ", c);
//             for (int j = 0; followSets[c - 'A'][j] != '\0'; j++) {
//                 if (j > 0) printf(", ");
//                 printf("%c", followSets[c - 'A'][j]);
//             }
//             printf(" }\n");
//             printed[c - 'A'] = 1; // Mark as printed
//         }
//     }

//     return 0;
// }























#include <stdio.h>

int main() {
    int A, B, C, D, E;
    int t1, t2, t3;

    printf("This program calculates the value of the expression: A = B + C * D - E\n\n");

    printf("Please enter the value for B: ");
    scanf("%d", &B);
    printf("Please enter the value for C: ");
    scanf("%d", &C);
    printf("Please enter the value for D: ");
    scanf("%d", &D);
    printf("Please enter the value for E: ");
    scanf("%d", &E);

    t1 = C * D;
    printf("\nStep 1: C * D = %d * %d = %d\n", C, D, t1);

    t2 = B + t1;
    printf("Step 2: B + (C * D) = %d + %d = %d\n", B, t1, t2);

    t3 = t2 - E;
    printf("Step 3: (B + C * D) - E = %d - %d = %d\n", t2, E, t3);

    A = t3;
    printf("Step 4: A = %d\n", A);

    printf("\nThe final result of the expression A = B + C * D - E is: %d\n", A);

    return 0;
}
