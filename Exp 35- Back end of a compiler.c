#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char a[50][50];
	printf("enter the no: intermediate code:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the 3 address code:%d:",i+1);
		for(j=0;j<6;j++)
		{
			scanf("%c",&a[i][j]);
		}
	}
	printf("the generated code is:");
	for(i=0;i<n;i++)
	{
		printf("\n mov %c,R%d",a[i][3],i);
		if(a[i][4]=='-')
		{
			printf("\n sub %c,R%d",a[i][5],i);
		}
		if(a[i][4]=='+')
		{
			printf("\n add %c,R%d",a[i][5],i);
		}
		if(a[i][4]=='*')
		{
			printf("\n mul %c,R%d",a[i][5],i);
		}
		if(a[i][4]=='/')
		{
			printf("\n div %c,R%d",a[i][5],i);
		}
		printf("\n mov R%d,%c",i,a[i][1]);
		printf("\n");
	}
	return 0;
}
OUTPUT:
enter the no: intermediate code:4
enter the 3 address code:1:t1=int to real(60)
enter the 3 address code:2:enter the 3 address code:3:enter the 3 address code:4:t2=id3*t1
the generated code is:
 mov =,R0
 mov R0,t

 mov o,R1
 mov R1,

 mov (,R2
 mov R2,a

 mov 2,R3
 mov R3,


--------------------------------
Process exited after 71.86 seconds with return value 0
Press any key to continue . . .
