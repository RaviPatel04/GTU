#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

// Function prototypes for grammar rules
int E(), Edash(), T(), Tdash(), F();

const char *cursor;
char string[64];

int main() {
    // Get input string
    puts("Enter the string:");
    scanf("%63s", string);
    cursor = string;
    
    puts("");
    puts("Input\t\tAction");
    puts("\t");
    
    // Start parsing from the start symbol (E)
    if (E() && *cursor == '\0') {
        puts("\t");
        puts("String is successfully parsed");
        return 0;
    } else {
        puts("\t");
        puts("Error in parsing String");
        return 1;
    }
}

// Parsing E -> T E'
int E() {
    printf("%-16s E -> T E'\n", cursor);
    if (T()) {
        if (Edash())
            return SUCCESS;
        else
            return FAILED;
    } else {
        return FAILED;
    }
}

// Parsing E' -> + T E' | ε
int Edash() {
    if (*cursor == '+') {
        printf("%-16s E' -> + T E'\n", cursor);
        cursor++;
        if (T()) {
            if (Edash())
                return SUCCESS;
            else
                return FAILED;
        } else {
            return FAILED;
        }
    } else {
        printf("%-16s E' -> $\n", cursor);
        return SUCCESS;
    }
}

// Parsing T -> F T'
int T() {
    printf("%-16s T -> F T'\n", cursor);
    if (F()) {
        if (Tdash())
            return SUCCESS;
        else
            return FAILED;
    } else {
        return FAILED;
    }
}

// Parsing T' -> * F T' | ε
int Tdash() {
    if (*cursor == '*') {
        printf("%-16s T' -> * F T'\n", cursor);
        cursor++;
        if (F()) {
            if (Tdash())
                return SUCCESS;
            else
                return FAILED;
        } else {
            return FAILED;
        }
    } else {
        printf("%-16s T' -> $\n", cursor);
        return SUCCESS;
    }
}

// Parsing F -> ( E ) | i
int F() {
    if (*cursor == '(') {
        printf("%-16s F -> ( E )\n", cursor);
        cursor++;
        if (E()) {
            if (*cursor == ')') {
                cursor++;
                return SUCCESS;
            } else {
                return FAILED;
            }
        } else {
            return FAILED;
        }
    } else if (*cursor == 'i') {
        cursor++;
        printf("%-16s F -> i\n", cursor);
        return SUCCESS;
    } else {
        return FAILED;
    }
}
