%{
#include<stdio.h>
float op1=6,op2=7;
%}

%%
"+" {printf("sum =%lf",op1+op2);}
"-" {printf("diff=%lf",op1-op2);}
"*" {printf("mul=%lf",op1*op2);}
"/" {printf("div=%lf",op1/op2);}
. {printf("enter proper operator.");}
%%

int yywrap(){}
int main()
{
printf("Enter the Operator::");
yylex();
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex mathematical.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
Enter the Operator::*
mul=42.000000
+
sum =13.000000
-
diff=-1.000000
/
div=0.857143
%
enter proper operator.
