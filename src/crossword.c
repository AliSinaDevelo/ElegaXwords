#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "crossword.h"

#define MAX_SIZE 20

static char crosswordGrid[MAX_SIZE][MAX_SIZE];
static struct Word placedWords[MAX_WORDS];

// Function to check if a word can be placed at a given position (horizontal)
static bool canPlaceHorizontally(const char* word, int row, int col, int numCols) {
    int len = strlen(word);
    if (col + len > numCols)
        return false;

    for (int i = 0; i < len; i++) {
        if (crosswordGrid[row][col + i] != ' ' && crosswordGrid[row][col + i] != word[i])
            return false;
    }

    return true;
}

// Function to check if a word can be placed at a given position (vertical)
static bool canPlaceVertically(const char* word, int row, int col, int numRows) {
    int len = strlen(word);
    if (row + len > numRows)
        return false;

    for (int i = 0; i < len; i++) {
        if (crosswordGrid[row + i][col] != ' ' && crosswordGrid[row + i][col] != word[i])
            return false;
    }

    return true;
}

// Function to place a word horizontally at a given position
static void placeHorizontally(const char* word, int row, int col) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        crosswordGrid[row][col + i] = word[i];
    }
}

// Function to place a word vertically at a given position
static void placeVertically(const char* word, int row, int col) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        crosswordGrid[row + i][col] = word[i];
    }
}

// Function to remove a placed word from the grid
static void removeWord(const struct Word* word) {
    int len = strlen(word->word);
    if (word->horizontal) {
        for (int i = 0; i < len; i++) {
            crosswordGrid[word->row][word->col + i] = ' ';
        }
    } else {
        for (int i = 0; i < len; i++) {
            crosswordGrid[word->row + i][word->col] = ' ';
        }
    }
}

// Function to generate the crossword using backtracking
static bool generateCrosswordUtil(struct Word wordList[], int numWords, int wordIndex, int numRows, int numCols) {
    if (wordIndex == numWords) {
        return true; // All words are placed successfully
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (canPlaceHorizontally(wordList[wordIndex].word, row, col, numCols)) {
                placeHorizontally(wordList[wordIndex].word, row, col);
                wordList[wordIndex].row = row;
                wordList[wordIndex].col = col;
                wordList[wordIndex].horizontal = true;

                bool success = generateCrosswordUtil(wordList, numWords, wordIndex + 1, numRows, numCols);
                if (success)
                    return true;

                removeWord(&wordList[wordIndex]);
            }

            if (canPlaceVertically(wordList[wordIndex].word, row, col, numRows)) {
                placeVertically(wordList[wordIndex].word, row, col);
                wordList[wordIndex].row = row;
                wordList[wordIndex].col = col;
                wordList[wordIndex].horizontal = false;

                bool success = generateCrosswordUtil(wordList, numWords, wordIndex + 1, numRows, numCols);
                if (success)
                    return true;

                removeWord(&wordList[wordIndex]);
            }
        }
    }

    return false; // Unable to place the word
}

// Function to display the crossword grid
static void displayCrossword(int numRows, int numCols, bool displaySolution) {
    printf("\nGenerated Crossword:\n");
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (displaySolution || crosswordGrid[row][col] == ' ')
                printf("%c ", crosswordGrid[row][col]);
            else
                printf("_ ");
        }
        printf("\n");
    }
}

bool generateCrossword(struct Word wordList[], int numWords, int numRows, int numCols, bool displaySolution) {
    if (numWords == 0 || numRows <= 0 || numCols <= 0 || numWords > MAX_WORDS) {
        return false; // Invalid input
    }

    // Initialize the crossword grid with empty cells
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            crosswordGrid[row][col] = ' ';
        }
    }

    if (!generateCrosswordUtil(wordList, numWords, 0, numRows, numCols)) {
        return false; // Unable to generate the crossword
    }

    displayCrossword(numRows, numCols, displaySolution);

    return true; // Crossword generated successfully
}

