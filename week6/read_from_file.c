#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 10
#define COLS 3

void tokenize(char *input, int *array, int size) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, ",");
    int i = 0;
    while (token != NULL && i < size) {
        array[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
    free(inputCopy);
}

void createArray(int data[ROWS][COLS], int *values, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = values[i * cols + j];
        }
    }
}

int main() {
    FILE *file = fopen("marks.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    char line[100];
    fgets(line, sizeof(line), file);
    fclose(file);
    int values[ROWS * COLS];
    tokenize(line, values, ROWS*COLS);
    int data[ROWS][COLS];
    createArray(data, values, ROWS, COLS);
    printf("The students marks are:\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}