%{
int vow_count=0;
int const_count=0;
%}

%%

[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%
int yywrap(){}
int main()
{
printf("Enter the string of vowels and consonants:");
yylex();
printf("Number of vowels are: %d\n",vow_count);
printf("Number of consonants are: %d\n",const_count);
return 0;
}
OUTPUT:
C:\Users\malsr>set path=C:\Program Files (x86)\GnuWin32\bin

C:\Users\malsr>flex vowels.l.txt

C:\Users\malsr>set path=C:\MinGW\bin

C:\Users\malsr>gcc lex.yy.c

C:\Users\malsr>a
Enter the string of vowels and consonants:compiler

Number of vowels are: 3
Number of consonants are: 5
