%{
%}

%%
"http://www."[a-z]+".com" {printf("it is an valid url.");}
.+ {printf("It is not an url.");}
%%

int yywrap()
{}

int main()
{
printf("Enter the URL::");
yylex();
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex url.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
Enter the URL::http://www.ABCD.com
It is not an url.
