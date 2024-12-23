// Extract HTML Tags


%{
#include <stdio.h>
%}

%%
"<[^>]+>"   { printf("HTML Tag: %s\n", yytext); }
.           { /* Ignore */ }
%%

int main() {
    printf("Enter HTML content: ");
    yylex();
    return 0;
}
