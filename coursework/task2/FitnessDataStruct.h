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
void read_from_file(FILE *file, FITNESS_DATA data);
int number_of_records(FILE *file);

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
        perror("");
        exit(1);
    }
	return file;
}

void read_from_file(FILE *file, FITNESS_DATA data)
{
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        char dataline[25];
        strcpy(dataline, line_buffer);
        char my_delimiter = ',';
        char my_date[11];
        char my_time[6];
        char my_steps[8];
        tokeniseRecord(dataline, &my_delimiter, my_date, my_time, my_steps);
		strcpy(data.date, my_date);
		strcpy(data.time, my_time);
		data.steps = atoi(my_steps);
		printf("%s %s %d \n", data.date, data.time, data.steps);
	}
}

#endif