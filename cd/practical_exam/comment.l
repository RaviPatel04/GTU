//Extract Comments from C Program

%{
#include <stdio.h>
%}

%%
"/*"([^*]|\*+[^/])*"*"/   { printf("Multiline Comment: %s\n", yytext); }
"//".*                     { printf("Single-line Comment: %s\n", yytext); }
.                          { /* Ignore */ }
%%

int main() {
    printf("Enter a C program: ");
    yylex();
    return 0;
}
