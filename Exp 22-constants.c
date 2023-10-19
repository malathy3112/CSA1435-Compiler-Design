%{
#include<stdio.h>
int cons=0;
%}
%%
[0-9]+ { cons++; printf("%s is a constant\n", yytext);  }
.|\n { }
%%
int yywrap() 
{
return 1; 
}
int main(int argc,char* argv[])
{
printf("enter the string:\n");
yylex();
printf("Number of Constants : %d\n", cons);
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex constant.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
enter the string:
a=2+3
2 is a constant
3 is a constant
b=69+3112
69 is a constant
3112 is a constant
