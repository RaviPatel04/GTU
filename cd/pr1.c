#include <stdio.h>
#include <string.h>

int checkString(char str[]) {
    int length = strlen(str);
    if (str[0] == 'b'  && str[length - 1] == 'a') {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    char str[100];
    printf("Enter a string(start with 'b' and end with 'a'): ");
    scanf("%s", str);

    if (checkString(str)) {
        printf("String is accepted!!\n");
    } else {
        printf("String is not accepted!!\n");
    }

    return 0;
}
