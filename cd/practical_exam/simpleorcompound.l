//Check Simple or Compound Statement


%{
#include <stdio.h>
%}

%%
"and"|"or"   { printf("Compound Statement\n"); }
.            { printf("Simple Statement\n"); }
%%

int main() {
    printf("Enter a statement: ");
    yylex();
    return 0;
}
