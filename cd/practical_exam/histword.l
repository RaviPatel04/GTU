// Generate Histogram of Words


%{
#include <stdio.h>
#include <string.h>
%}

%%
[a-zA-Z]+   { printf("%s\n", yytext); }
\n           { /* Ignore */ }
.            { /* Ignore */ }
%%

int main() {
    printf("Enter text: ");
    yylex();
    return 0;
}
