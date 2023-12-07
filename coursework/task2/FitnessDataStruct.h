#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
FILE *open_file(char filename[], char mode[]);
int read_from_file(FILE *file, FITNESS_DATA *data);
int fewest_steps(int records, FITNESS_DATA *data);
int largest_steps(int records, FITNESS_DATA *data);
int mean(int records, FITNESS_DATA *data);
void longest_period(int records, FITNESS_DATA *data);

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) 
{
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
        i++;
	}
    printf("File successfully loaded.\n");
    return i;
}

int fewest_steps(int records, FITNESS_DATA *data)
{
    int pointer;
    int lowest = -1;
    for(int i = 0; i < records; i++)
    {
        if (lowest == -1)
        {
            lowest = data[i].steps;
        }
        if (data[i].steps < lowest)
        {
            lowest = data[i].steps;
            pointer = i;
        }
    }
    return pointer;
}

int largest_steps(int records, FITNESS_DATA *data)
{
    int pointer;
    int highest = -1;
    for(int i = 0; i < records; i++)
    {
        if (highest == -1)
        {
            highest = data[i].steps;
        }
        if (data[i].steps > highest)
        {
            highest = data[i].steps;
            pointer = i;
        }
    }
    return pointer;
}

int mean(int records, FITNESS_DATA *data)
{
    float total = 0;
    for(int i = 0; i < records; i++)
    {
        total += data[i].steps;
    }
    float mean = total/records;
    int rounded = round(mean);
    return rounded;
}

void longest_period(int records, FITNESS_DATA *data)
{
    int period = 0;
    int longest = 0;
    int longest_start;
    int longest_end;
    int start;
    int i;
    for(i = 0; i < records; i++)
    {
        period = 0;
        if (data[i].steps > 500)
        {
            start = i;
        }
        while(data[i].steps > 500)
        {
            period++;
            if (period > longest)
            {
                longest = period;
                longest_start = start;
                longest_end = i;
            }
            i++;
        }
    }
    printf("Longest period start: %s %s \n", data[longest_start].date, data[longest_start].time);
    printf("Longest period end: %s %s \n", data[longest_end].date, data[longest_end].time);
}

#endif