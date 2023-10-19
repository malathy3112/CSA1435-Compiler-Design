#include <stdio.h>

int main() {
    char ch;
    int spaceCount = 0;
    int newlineCount = 0;

    printf("Enter text (press Ctrl+D to end input):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t') {
            spaceCount++;
        } else if (ch == '\n') {
            newlineCount++;
        }
    }

    printf("Whitespace count: %d\n", spaceCount);
    printf("Newline count: %d\n", newlineCount);

    return 0;
}
 /* OUTPUT:
    Enter text (press Ctrl+D to end input):
This is a sample text with
some newlines and spaces.
   
Whitespace count: 8
Newline count: 2 */
