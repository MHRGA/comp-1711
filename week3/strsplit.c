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

int main() 
{
    char dataline[] = "2023-09-01,12:15,270";
    char my_delimiter = ',';
    char my_date[11];
    char my_time[6];
    char my_steps[8];
    tokeniseRecord(dataline, &my_delimiter, my_date, my_time, my_steps);
    printf("%s\n", my_date);
    printf("%s\n", my_time);
    printf("%s\n", my_steps);
    int steps_as_int = atoi(my_steps);
    printf("%d\n", steps_as_int);
    return 0;
}