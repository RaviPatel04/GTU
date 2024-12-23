//Caesar Cipher

%{
#include <stdio.h>
#define SHIFT 3
%}

%%
[a-z]   { printf("%c", ((yytext[0] - 'a' + SHIFT) % 26) + 'a'); }
[A-Z]   { printf("%c", ((yytext[0] - 'A' + SHIFT) % 26) + 'A'); }
.       { printf("%s", yytext); }
%%

int main() {
    printf("Enter text: ");
    yylex();
    return 0;
}
