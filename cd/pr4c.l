%{ 
#include <stdio.h>
%}

%% 
"<"[^>]*">" { printf("%s\n", yytext); } // Match and print HTML tags
. ; // Ignore other characters
%% 

int yywrap() {
    return 1; // End of input
}

int main(int argc, char *argv[]) { 
    yyin = fopen("pr.html", "r"); // Open the input file
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }
    yylex(); // Start lexical analysis
    fclose(yyin); // Close the input file
    return 0; 
}
