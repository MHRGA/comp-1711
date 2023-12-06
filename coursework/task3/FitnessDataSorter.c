#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

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

void read_from_file(FILE *file, FITNESS_DATA *data, char filename[])
{
    int i = 0;
    strcat(filename, ".tsv");
    FILE *newfile = fopen(filename, "w");
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) 
    {
        char my_steps[10];
        tokeniseRecord(line_buffer, ",", data[i].date, data[i].time, my_steps);
        data[i].steps = atoi(my_steps);
        fprintf(newfile, "%s\t%s\t%d \n", data[i].date, data[i].time, data[i].steps);
        i++;
	}
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

int main() {
    char filename[100];
    FITNESS_DATA data[500];
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *file = open_file(filename, "r");
    read_from_file(file, data, filename);
}