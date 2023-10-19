%{
#include<stdio.h>
%}

%%

if|else|while|int|switch|for|char { printf("\n%s is a KEYWORD", yytext);}
[a-zA-Z0-9]+ { printf("\n%s is IDENTIFIER", yytext);}

%%
int yywrap( ){}
int main()
{
	yylex();
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex keyide.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
int

int is a KEYWORD
main

main is IDENTIFIER
