%{
#include<stdio.h>
%}

%%

if|else|while|int|switch|for|char { printf("\n%s is Not a IDENTIFIER", yytext);}
[a-zA-Z0-9]+ { printf("\n%s is IDENTIFIER", yytext);}

%%
int yywrap( ){}
int main()
{
	yylex();
}

/*output:
Microsoft Windows [Version 10.0.22621.2428]
(c) Microsoft Corporation. All rights reserved.

C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex identifierORnot.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
int a if a else b

int is Not a IDENTIFIER
a is IDENTIFIER
if is Not a IDENTIFIER
a is IDENTIFIER
else is Not a IDENTIFIER
b is IDENTIFIER*/
