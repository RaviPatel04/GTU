%{ 
#include <stdio.h>  
int total = 0; 
%}

WS [ \t]+

%% 
I       { total += 1; }  
IV      { total += 4; } 
V       { total += 5; }  
IX      { total += 9; } 
X       { total += 10; }  
XL      { total += 40; } 
L       { total += 50; }  
XC      { total += 90; } 
C       { total += 100; }  
CD      { total += 400; } 
D       { total += 500; }  
CM      { total += 900; } 
M       { total += 1000; } 
{WS}    ; // Skip whitespace
\n      { /* End of input; do nothing */ }  
.       { /* Ignore any unrecognized character */ }
%% 

int main(void) 
{ 
    printf("Enter Roman Number: ");  
    yylex();  // Start lexical analysis
    printf("Decimal Number is: %d\n", total);  
    return 0; 
} 

int yywrap(void) 
{ 
    return 1; 
}
