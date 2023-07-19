#include <stdio.h>
#include <stdbool.h>
#include "crossword.h" // Include the crossword generation functions
#include <string.h>

int main() {
    int numWords, numRows, numCols;
    bool displaySolution;
    struct Word wordList[MAX_WORDS];

    printf("Welcome to ElegaXWords - Crossword Generator!\n");

    // Step 1: Input Words
    printf("Enter the number of words: ");
    scanf("%d", &numWords);

    printf("Enter the words:\n");
    for (int i = 0; i < numWords; i++) {
        scanf("%s", wordList[i].word);
        wordList[i].length = strlen(wordList[i].word);
    }

    // Step 2: Get Crossword Grid Size
    printf("Enter the number of rows for the crossword grid: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns for the crossword grid: ");
    scanf("%d", &numCols);

    // Step 3: Display Solution Option
    printf("Do you want to display the solution? (1 for Yes, 0 for No): ");
    scanf("%d", &displaySolution);

    // Step 4: Generate and Display the Crossword
    bool success = generateCrossword(wordList, numWords, numRows, numCols, displaySolution);
    if (!success) {
        printf("Unable to generate a crossword with the given input.\n");
    }

    return 0;
}

