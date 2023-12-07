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

void write_to_file(FITNESS_DATA *data, int records, char filename[])
{
    strcat(filename, ".tsv");
    FILE *newfile = fopen(filename, "w");
    for (int i = 0; i < records; i++)
    {
        fprintf(newfile, "%s\t%s\t%d \n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(newfile);
}

void swap_record(int a, int b, FITNESS_DATA *data)
{
    char temp_date[11];
    char temp_time[6];
    strcpy(temp_date, data[a].date);
    strcpy(temp_time, data[a].time);
    int temp_steps = data[a].steps;
    strcpy(data[a].date, data[b].date);
    strcpy(data[a].time, data[b].time);
    data[a].steps = data[b].steps;
    strcpy(data[b].date, temp_date);
    strcpy(data[b].time, temp_time);
    data[b].steps = temp_steps;
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

void check_record(char date, char time)
{
    if (date != '-' || time != ':')
    {
        printf("Error: File incorrectly formatted.\n");
        exit(0);
    }
}

int read_from_file(FILE *file, FITNESS_DATA *data)
{
    int i = 0;
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) 
    {
        char my_steps[10];
        tokeniseRecord(line_buffer, ",", data[i].date, data[i].time, my_steps);
        data[i].steps = atoi(my_steps);
        check_record(data[i].date[4], data[i].time[2]);
        i++;
	}
    return i;
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
    int records = read_from_file(file, data);
    int lowest_pointer = fewest_steps(records, data);
    int highest_pointer = largest_steps(records, data);
    swap_record(lowest_pointer, records - 1, data);
    swap_record(highest_pointer, 0, data);
    write_to_file(data, records, filename);
}