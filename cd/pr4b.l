%{
#include <stdio.h>
int flag = 0; 
%}

%% 
and | 
or | 
but | 
because | 
if | 
then | 
nevertheless { flag = 1; } 
. ; 
\n { /* End of line, do nothing */ } 
%% 

int main() { 
    printf("Enter the sentence:\n"); 
    yylex(); 

    // Determine if the sentence is simple or compound
    if (flag == 0) {
        printf("Simple sentence\n");
    } else {
        printf("Compound sentence\n");
    }

    return 0; 
} 

int yywrap(void) { 
    return 1; 
}
