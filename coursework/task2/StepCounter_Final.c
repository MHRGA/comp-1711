#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FitnessDataStruct.h"


int main() {
    char filename[100];
    while(1)
    {
        char choice[2];
        printf("1st Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");
        scanf("%s",choice);
        while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C' && toupper(choice[0]) != 'D' && toupper(choice[0]) != 'E' && toupper(choice[0]) != 'F' && toupper(choice[0]) != 'Q')
        {
            printf("Invalid choice. Try again.\n");
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
        }
        switch (toupper(choice[0]))
        {
            case 'A':
                printf("Please enter the name of the file you want to open: ");
                scanf("%s", filename);
                FILE *file = open_file(filename , "r");
                FITNESS_DATA data;
                read_from_file(file, data);
                break;
            case 'B':
                printf("Total records: %d", number_of_records(file));
                break;
        }
    }
}