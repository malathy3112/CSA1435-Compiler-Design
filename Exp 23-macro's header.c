%{
int nmacro, nheader; 
%}
%%
^#define { nmacro++; } 
^#include { nheader++; } 
.|\n { } 
%%
int yywrap() 
{ 
return 1; 
} 
int main(int argc, char *argv[]) 
{ 
printf("enter the string:\n");
yylex(); 
printf("Number of macros defined = %d\n", nmacro); 
printf("Number of header files included = %d\n", nheader); 
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex macro.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
Number of macros defined = 1
Number of header files included = 1
