#include <stdio.h>
#include <string.h>

char first[100];
char c;

// Function prototypes
void FiS();
void FiA();
void FiB();
void FiC();

void FiS() {
    // Assume FiS generates the First set for non-terminal S
    FiA();
    strcat(first, ", ");
    FiB();
}

void FiA() {
    // Example First set for non-terminal A
    strcpy(first, "{a, d}");
}

void FiB() {
    // Example First set for non-terminal B
    strcpy(first, "{b, f}");
}

void FiC() {
    // Example First set for non-terminal C
    strcpy(first, "{g}");
}

int main() {
    char r;
    printf("Enter your Non Terminal:\n");
    scanf(" %c", &r); // Added a space before %c to skip any leading whitespace

    // Clear the previous First set
    first[0] = '\0';

    if (r == 'S') {
        FiS();
    } else if (r == 'A') {
        FiA();
    } else if (r == 'B') {
        FiB();
    } else if (r == 'C') {
        FiC();
    } else {
        printf("INVALID NON TERMINAL\n");
        return 1;
    }

    printf("First of '%c' is: %s\n", r, first);
    return 0;
}
