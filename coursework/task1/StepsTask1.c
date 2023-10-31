#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number_of_records(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    int buffer_size = 100;
    char line_buffer[buffer_size];
    int i;
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        i++;
    }
    return i;
}

char read_from_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    int buffer_size = 23;
    char line_buffer[buffer_size];
    int i;
    for(i=0;i<3;i++) {
        fgets(line_buffer, buffer_size, file);
        char dataline[25];
        strcpy(dataline, line_buffer);
        char my_delimiter = ',';
        char my_date[11];
        char my_time[6];
        char my_steps[8];
        tokeniseRecord(dataline, &my_delimiter, my_date, my_time, my_steps);
        printf("%s/%s/%s", my_date, my_time, my_steps);
    }
    fclose(file);
}

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    free(inputCopy);
}

int main() {
    char filename [] = "FitnessData_2023.csv";
    printf("Number of records in file: %d\n", number_of_records(filename, "r"));
    read_from_file(filename, "r");
    return 0;
}