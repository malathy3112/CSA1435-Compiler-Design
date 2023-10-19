%{
int positive_no = 0, negative_no = 0;
%}

%%
^[-][0-9]+ {negative_no++;
			printf("negative number = %s\n",yytext);} 

[0-9]+ {positive_no++;
		printf("positive number = %s\n",yytext);}	

%%

int yywrap(){}
int main()											
{
printf("enter the numbers:");

yylex();
printf ("number of positive numbers = %d,"
		"number of negative numbers = %d\n",
				positive_no, negative_no);

return 0;
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex posneg.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
enter the numbers:69
positive number = 69

-76
negative number = -76
