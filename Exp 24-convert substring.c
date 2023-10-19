%{
#include <stdio.h>
%}
%%
abc {
    printf("ABC");
}
. {
    printf("%c", yytext[0]);
}
%%
int yywrap( ){}
int main() {
    printf("Enter the string:");
    yylex();
    return 0;
}

/*OUTPUT:
Enter the string: abc
ABC */
