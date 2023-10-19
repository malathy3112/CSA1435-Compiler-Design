%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap

%{
#define MAX_LEN 100

char alphabet_list[MAX_LEN];
char number_list[MAX_LEN];
int alpha_index = 0;
int num_index = 0;

void clear_lists() {
    memset(alphabet_list, 0, MAX_LEN);
    memset(number_list, 0, MAX_LEN);
    alpha_index = 0;
    num_index = 0;
}
%}

%%
[a-zA-Z] {
    alphabet_list[alpha_index++] = yytext[0];
}
[0-9]+ {
    number_list[num_index++] = yytext[0];
}
. {
    // Ignore other characters
}
%%

int main() {
    clear_lists();
    
    printf("Enter a string: ");
    yylex();
    
    printf("Alphabets: %s\n", alphabet_list);
    printf("Numbers: %s\n", number_list);
    
    return 0;
}


/*OUTPUT:
Enter a string: HELLO world Bye 1 23 45 67
Alphabets: HELLO world Bye
Numbers: 1 23 45 67 */
