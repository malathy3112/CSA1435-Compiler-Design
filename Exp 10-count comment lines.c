%{
#include<stdio.h>
int n=0;
%}

%%
"/*"[a-zA-Z0-9 \n\t]+"*/" {n++;}
"//"[a-zA-Z0-9 \n\t]+"//" {n++;}
%%

int yywrap()
{}

int main()
{
printf("enter:");
yylex();
printf("no of comment lines:%d",n);
}

/*OUTPUT:
C:\Users\LOKESH KUMAR>a
enter:// Hello world
/* hello */
// Hello world

// hello
//bye
no of comment lines:5*/
