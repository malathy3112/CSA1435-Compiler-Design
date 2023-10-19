#include <stdio.h>
int main(void)
{
    char buff[10];
    int r;
    r = 1;
    printf("enter the string::");
    scanf("%*[ ]");
    while (r == 1) 
	{
        r = scanf("%9[^ \n]%*[ ]", buff);
        if (r == 1) 
		fputs(buff, stdout);
    }
    putchar('\n');
    return 0;
}

/* Output:
enter the string::Hello I am A Indian
HelloIamAIndian

--------------------------------
Process exited after 20.37 seconds with return value 0
Press any key to continue . . . */
