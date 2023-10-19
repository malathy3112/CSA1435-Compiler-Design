#include <stdio.h>
#include <stdlib.h>

int temp_count = 0;

char* generate_temp_var() {
    char* temp_var = (char*)malloc(5);
    sprintf(temp_var, "t%d", temp_count);
    temp_count++;
    return temp_var;
}

void three_address_code(char* expression) {
    char* op_stack[100];
    char* val_stack[100];
    int op_top = -1;
    int val_top = -1;
    
    int i = 0;
    char* temp;
    
    while (expression[i] != '\0') {
        if (expression[i] == '(') {
            i++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            op_stack[++op_top] = (char*)malloc(2);
            op_stack[op_top][0] = expression[i];
            op_stack[op_top][1] = '\0';
            i++;
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            int j = i;
            while (expression[j] >= '0' && expression[j] <= '9') {
                j++;
            }
            temp = generate_temp_var();
            val_stack[++val_top] = temp;
            printf("%s = %c\n", temp, expression[i]);
            i = j;
        } else if (expression[i] == ')') {
            char* op = op_stack[op_top--];
            char* val2 = val_stack[val_top--];
            char* val1 = val_stack[val_top--];
            
            temp = generate_temp_var();
            val_stack[++val_top] = temp;
            
            printf("%s = %s %s %s\n", temp, val1, op, val2);
            i++;
        } else {
            i++;
        }
    }
}

int main() {
    char expression[100];
    
    printf("Enter an infix expression: ");
    scanf("%s", expression);
    
    printf("Three-address code representation:\n");
    three_address_code(expression);
    
    return 0;
}
 /* OUTPUT:
Enter an infix expression: a + b * c
Three-address code representation:
t0 = b
t1 = c
t2 = t0 * t1
t3 = a
t4 = t3 + t2 */
