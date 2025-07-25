#include <stdio.h>

#define ROWS 10
#define COLS 3

void writeMatrixToFile(int matrix[ROWS][COLS], const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fprintf(file, "%d", matrix[i][j]);
            if (!(i == ROWS - 1 && j == COLS - 1)) {
                fprintf(file, ",");
            }
        }
    }
    fclose(file);
}

int main() {
    int Marks_Matrix[ROWS][COLS] = {
        {72, 68, 100},
        {87, 80, 92},
        {91, 79, 99},
        {93, 85, 80},
        {73, 69, 55},
        {94, 96, 88},
        {79, 84, 90},
        {93, 83, 89},
        {84, 65, 78},
        {94, 93, 97}
    };
    const char *filename = "output.txt";
    writeMatrixToFile(Marks_Matrix, filename);
    printf("Marks written to %s.\n", filename);
    return 0;
}