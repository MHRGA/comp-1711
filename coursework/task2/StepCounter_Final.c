#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FitnessDataStruct.h"


int main() {
    char filename[100];
    FITNESS_DATA data[500];
    int i;
    int j;
    while(1)
    {
        char choice[2];
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");
        scanf("%s",choice);
        switch (toupper(choice[0]))
        {
            case 'A':
                printf("Please enter the name of the file you want to open: ");
                scanf("%s", filename);
                FILE *file = open_file(filename , "r");
                int records = read_from_file(file, data);
                break;
            case 'B':
                printf("Total records: %d \n", records);
                break;
            case 'C':
                i = fewest_steps(records, data);
                printf("Fewest steps: %s %s \n", data[i].date, data[i].time);
                break;
            case 'D':
                j = largest_steps(records, data);
                printf("Largest steps: %s %s \n", data[j].date, data[j].time);
                break;
            case 'E':
                printf("Mean step count: %d \n", mean(records, data));
                break;
            case 'F':
                longest_period(records, data);
                break;
            case 'Q':
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}