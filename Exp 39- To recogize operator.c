#include <stdio.h>
int main() {
  char c;
  printf("Enter the operator: ");
  scanf("%c", &c);
  switch (c) {
    case '+':
      printf("The operator is addition.\n");
      break;
    case '-':
      printf("The operator is subtraction.\n");
      break;
    case '*':
      printf("The operator is multiplication.\n");
      break;
    case '/':
      printf("The operator is division.\n");
      break;
    case '%':
      printf("The operator is modulo.\n");
      break;
    default:
      printf("Invalid operator.\n");
      break;
  }
  return 0;
}

\\*OUTPUT
Enter the operator: 34+21+2
Invalid operator.

Enter the operator: *
The operator is multiplication.
--------------------------------
Process exited after 14.52 seconds with return value 0
Press any key to continue . . .
*\\
