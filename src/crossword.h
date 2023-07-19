#ifndef CROSSWORD_H
#define CROSSWORD_H

#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int length;
    int row;
    int col;
    bool horizontal;
};

bool generateCrossword(struct Word wordList[], int numWords, int numRows, int numCols, bool displaySolution);

#endif // CROSSWORD_H

