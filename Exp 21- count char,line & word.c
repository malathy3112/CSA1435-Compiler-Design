%{
#include<stdio.h>
int lc=0,sc=0,ch=0,wc=0;        
%}
 
 
%%
[\n] { lc++; ch+=yyleng;}
[  \t] { sc++; ch+=yyleng;}
[^\t\n ]+ { wc++;  ch+=yyleng;} 
%%
 
int yywrap(){ return 1;    }
/*        After inputting press ctrl+c        */
 
int main(){
    printf("Enter the Sentence : ");
    yylex();
    printf("Number of lines : %d\n",lc);
    printf("Number of spaces : %d\n",sc);
    printf("Number of  words: %d\n",wc);
     printf("Number of  charcters: %d\n",ch);
     
    return 0;
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex wordcharline.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
Enter the Sentence : compiler design
csa1435Number of lines : 1
Number of spaces : 2
Number of  words: 2
^C
