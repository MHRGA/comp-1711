#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

FILE *open_file(char filename[], char mode[]);
int read_from_file(FILE *file, FITNESS_DATA *data);

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

FILE *open_file(char filename[], char mode[])
{
    FILE *file = fopen(filename , mode);
	if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }
	return file;
}

int read_from_file(FILE *file, FITNESS_DATA *data)
{
    int i = 0;
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        char my_steps[10];
        tokeniseRecord(line_buffer, ",", data[i].date, data[i].time, my_steps);
        data[i].steps = atoi(my_steps);
        printf("%s %s %d \n", data[i].date, data[i].time, data[i].steps);
        i++;
	}
    printf("File successfully loaded.\n");
    return i;
}

#endif