%{
#include <stdio.h>
%}

%option noyywrap

%%

"//".*[\n] { 
    printf("Single-line comment: %s\n", yytext); 
}

"/*"([^*]|\n|("*"+[^*/]|\n))*"*"+"/" { 
    printf("Multi-line comment: %s\n", yytext); 
}

. { 
    /* Ignore other characters */ 
}

%%

int main() { 
    yylex(); 
    return 0; 
}
