%{
#include<stdio.h>
%}

%%
[A-Z]+[\t\n ] { printf("%s",yytext); }
[a-z]+ {printf(" ");}
%%

int yywrap()
{}


int main()
{
printf("\n enter a string:");
yylex();
}

/* Output:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex capital.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a

 enter a string:Hello World Is A MAGIC
H  W  I  A MAGIC */
