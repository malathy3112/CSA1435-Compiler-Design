#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10
#define MAX_LEN 20

char productions[MAX_RULES][MAX_LEN];
int numRules = 0;

void eliminateLeftFactoring();
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

    eliminateLeftFactoring();

    printf("\nCFG after eliminating left factoring:\n");
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

void eliminateLeftFactoring() {
    int numModifiedRules = 0;
    char nonTerminal = productions[0][0];
    int commonPrefixLength = 0;
    char commonPrefix[MAX_LEN];

    for (int i = 0; i < numRules; i++) {
        int len = strlen(productions[i]);
        if (i == 0) {
            commonPrefixLength = 1;
            commonPrefix[0] = productions[i][3];
            commonPrefix[1] = '\0';
        } else {
            int j;
            for (j = 3; j < len && j < commonPrefixLength + 3; j++) {
                if (productions[i][j] != commonPrefix[j - 3]) {
                    break;
                }
            }
            if (j < len && j == commonPrefixLength + 3) {
                commonPrefixLength = j - 3;
            }
        }
    }

    if (commonPrefixLength == 0) {
        printf("No common prefix found.\n");
        return;
    }

    char newNonTerminal = 'A';

    for (int i = 0; i < numRules; i++) {
        int len = strlen(productions[i]);
        if (productions[i][0] == nonTerminal && len >= commonPrefixLength + 3 && strncmp(productions[i] + 3, commonPrefix, commonPrefixLength) == 0) {
            char newProduction[MAX_LEN];
            newProduction[0] = newNonTerminal;
            newProduction[1] = '-';
            newProduction[2] = '\0';
            strcat(newProduction, productions[i] + 3 + commonPrefixLength);
            addProduction(newProduction);
            numModifiedRules++;
            productions[i][0] = newNonTerminal;
        }
    }

    if (numModifiedRules > 0) {
        char newProduction[MAX_LEN];
        newProduction[0] = nonTerminal;
        newProduction[1] = '-';
        newProduction[2] = '\0';
        strcat(newProduction, commonPrefix);
        strcat(newProduction, newNonTerminal);
        addProduction(newProduction);
    }
}

/* INPUT:
S -> iEtS | iEtSeS | a
E -> b
q

OUTPUT:
Original CFG:
S -> iEtS | iEtSeS | a
E -> b

CFG after eliminating left factoring:
S -> iEtSP | a
P -> tSP | ε
E -> b */
