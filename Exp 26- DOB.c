%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%{
int is_valid_date(int year, int month, int day) {
    if (year < 1900 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }

    // Additional checks for valid month/day combinations could be added here.

    return 1;
}
%}

%%
[0-9]{4}-[0-9]{2}-[0-9]{2} {
    int year, month, day;
    if (sscanf(yytext, "%d-%d-%d", &year, &month, &day) == 3 && is_valid_date(year, month, day)) {
        printf("Valid DOB: %s\n", yytext);
    } else {
        printf("Invalid DOB: %s\n", yytext);
    }
}
. {
    printf("Invalid DOB: %s\n", yytext);
}
%%

int main() {
    yylex();
    return 0;
}

/* OUTPUT:
2004-09-03
Valid DOB */
