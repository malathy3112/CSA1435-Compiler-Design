#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValidIdentifier(const char* input) {
    // Check if the first character is a letter or underscore
    if (!isalpha(input[0]) && input[0] != '_') {
        return false;
    }

    // Check the rest of the characters
    for (int i = 1; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && input[i] != '_') {
            return false;
        }
    }

    return true;
}

int main() {
    char identifier[50];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("Valid identifier: %s\n", identifier);
    } else {
        printf("Invalid identifier: %s\n", identifier);
    }

    return 0;
}

/* OUTPUT:
Enter an identifier: my_variable123
Valid identifier: my_variable123

Enter an identifier: 123in
Invalid identifier: 123in */
