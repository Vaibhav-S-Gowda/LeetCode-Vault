char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows <= 1 || numRows >= len) return s;

    char** rows = malloc(numRows * sizeof(char*));
    int* rowLens = calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = malloc((len + 1) * sizeof(char));
    }

    int currentRow = 0;
    int goingDown = 0;

    for (int i = 0; i < len; i++) {
        int pos = rowLens[currentRow];
        rows[currentRow][pos] = s[i];
        rowLens[currentRow]++;

        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1;
    }

    char* result = malloc((len + 1) * sizeof(char));
    int resultIdx = 0;

    for (int i = 0; i< numRows; i++) {
        rows[i][rowLens[i]] = '\0';
        strcpy(result + resultIdx, rows[i]);
        resultIdx += rowLens[i];
        free(rows[i]);
    }

    free(rows);
    free(rowLens);
    
    result[len] = '\0';
    return result;
}