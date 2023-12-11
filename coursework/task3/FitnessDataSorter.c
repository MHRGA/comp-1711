#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
        fprintf(newfile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
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

void bubble_sort(int records, FITNESS_DATA *data)
{
    bool swapped;
    for (int i = 0; i < records; i++) {
        swapped = false;
        for (int j = 0; j < records - i - 1; j++) {
            if (data[j].steps < data[j + 1].steps) 
            {
                swap_record(j, j+1, data);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

void check_record(char date, char time, char my_steps[])
{
    for(int i = 0; i < strlen(my_steps); i++)
    {
        if (isdigit(my_steps[i]))
        {
            break;
        }
        else
        {
            printf("Error: File incorrectly formatted.\n");
            exit(1);
        }
    }
    if (date != '-' || time != ':')
    {
        printf("Error: File incorrectly formatted.\n");
        exit(1);
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
        check_record(data[i].date[4], data[i].time[2], my_steps);
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
    bubble_sort(records,data);
    write_to_file(data, records, filename);
}