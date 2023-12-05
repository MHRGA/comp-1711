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

void read_from_file(FILE *file, FITNESS_DATA data, char filename[])
{
    int i = 0;
    int length = 1;
    FITNESS_DATA *array;
    array = malloc(sizeof(data) * length);
	int buffer_size = 100;
    char line_buffer[buffer_size];
    strcat(filename, ".tsv");
    FILE *newfile = fopen(filename, "w");
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        char dataline[25];
        strcpy(dataline, line_buffer);
        char* my_delimiter = ",";
        char my_steps[5];
        tokeniseRecord(dataline, my_delimiter, array[i].date, array[i].time, my_steps);
        array[i].steps = atoi(my_steps);
		length++;
        array = realloc(array, sizeof(data) * length);
        fprintf(newfile, "%s\t%s\t%d \n", array[i].date, array[i].time, array[i].steps);
        i++;
	}
    fclose(file);
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
    FITNESS_DATA data;
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *file = open_file(filename, "r");
    read_from_file(file, data, filename);
}