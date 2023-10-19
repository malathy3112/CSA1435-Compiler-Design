#include <stdio.h>
#include <string.h>
char input[100];
int position = 0;
int parseE();
void shift() {
    printf("Shift: %c\n", input[position]);
    position++;
}
void reduce() {
    printf("Reduce\n");
    position--;
}
int parseE() {
    int result;
    char lookahead = input[position];

    if (lookahead == 'i') {
        shift();
        result = 1; // Matched "id"
    } else if (lookahead == '(') {
        shift();
        result = parseE();
        if (input[position] == ')') {
            shift();
        }
    } else {
        result = 0; // No match
    }
      while (input[position] == '+' || input[position] == '*') {
        char op = input[position];
        shift();
        int rhs = parseE();
        if (op == '+') {
            result = result + rhs;
        } else {
            result = result * rhs;
        }
    }

    return result;
}

int main() {
    printf("Enter an expression (e.g., id + id * id): ");
    scanf("%s", input);

    int result = parseE();

    if (result == 1 && input[position] == '\0') {
        printf("Valid expression!\n");
    } else {
        printf("Invalid expression!\n");
    }
  return 0;
}

/*OUTPUT:
Enter an expression (e.g., id + id * id): (id + id * id)
Shift: (
Shift: i
Shift: d
Reduce
Shift: +
Shift: i
Shift: d
Reduce
Shift: *
Shift: i
Shift: d
Reduce
Reduce
Reduce
Valid expression!
*/
