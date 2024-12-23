//Convert Roman to Decimal


%{
#include <stdio.h>
%}

%%
"I"   { printf("1 "); }
"V"   { printf("5 "); }
"X"   { printf("10 "); }
"L"   { printf("50 "); }
"C"   { printf("100 "); }
"D"   { printf("500 "); }
"M"   { printf("1000 "); }
.     { /* Ignore */ }
%%

int main() {
    printf("Enter a Roman numeral: ");
    yylex();
    return 0;
}
