#include <stdio.h>
#include <string.h> // Include this library to use strlen()

// Function to check if the string starts with '0' and ends with '1'
int checkString(char str[]) {
    int length = strlen(str);
    if (str[0] == '0' && str[length - 1] == '1') {
        return 1; // String is accepted
    } else {
        return 0; // String is not accepted
    }
}

int main() {
    char str[100]; // Assuming the string length won't exceed 100 characters
    printf("The string should start with 0 and end with 1\n");
    printf("Enter a string for check: ");
    scanf("%s", str);

    if (checkString(str)) {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}
