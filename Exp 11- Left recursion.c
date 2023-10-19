#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10
#define MAX_LEN 20

char productions[MAX_RULES][MAX_LEN];
char nonTerminal;
int numRules = 0;

void eliminateLeftRecursion();
void addProduction(const char* prod);
void displayProductions();

int main() {
    printf("Enter the CFG rules (Enter 'q' to stop):\n");

    while (1) {
        char input[MAX_LEN];
        scanf("%s", input);
        if (input[0] == 'q') {
            break;
        }
        addProduction(input);
    }

    printf("Original CFG:\n");
    displayProductions();

    eliminateLeftRecursion();

    printf("\nCFG after eliminating left recursion:\n");
    displayProductions();

    return 0;
}

void addProduction(const char* prod) {
    if (numRules < MAX_RULES) {
        strcpy(productions[numRules], prod);
        numRules++;
    } else {
        printf("Max rules reached.\n");
    }
}

void displayProductions() {
    for (int i = 0; i < numRules; i++) {
        printf("%s\n", productions[i]);
    }
}

void eliminateLeftRecursion() {
    for (int i = 0; i < numRules; i++) {
        if (productions[i][0] == productions[i][3]) {
            nonTerminal = productions[i][0];
            break;
        }
    }

    if (nonTerminal == 0) {
        printf("No left recursion found.\n");
        return;
    }

    char newNonTerminal = 'A';
    char tempProductions[MAX_RULES][MAX_LEN];
    int numNewRules = 0;
    int numModifiedRules = 0;

    for (int i = 0; i < numRules; i++) {
        if (productions[i][0] == nonTerminal) {
            strcpy(tempProductions[numNewRules], &productions[i][3]);
            tempProductions[numNewRules][strlen(tempProductions[numNewRules])] = newNonTerminal;
            tempProductions[numNewRules][strlen(tempProductions[numNewRules]) + 1] = '\0';
            numNewRules++;
        } else {
            strcpy(productions[numModifiedRules], productions[i]);
            numModifiedRules++;
        }
    }

    for (int i = 0; i < numModifiedRules; i++) {
        int len = strlen(productions[i]);
        for (int j = 0; j < len; j++) {
            if (productions[i][j] == nonTerminal) {
                productions[i][j] = newNonTerminal;
                break;
            }
        }
    }

    for (int i = 0; i < numNewRules; i++) {
        char newProduction[MAX_LEN];
        newProduction[0] = newNonTerminal;
        newProduction[1] = '-';
        newProduction[2] = '\0';
        strcat(newProduction, tempProductions[i]);
        addProduction(newProduction);
    }
}

/*OUTPUT:
S -> (L) | a
L -> L, S | S
q

Original CFG:
S -> (L) | a
L -> L, S | S

CFG after eliminating left recursion:
S -> (L) | a
L -> aL' | L'
L' -> ,SL' | ε*/
