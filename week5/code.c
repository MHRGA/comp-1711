#include "utilities.h"
#include <ctype.h>

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }

    while (fgets(line, buffer_size, input))
    {
        // split up the line and store it in the right place
        // using the & operator to pass in a pointer to the bloodIron so it stores it
        tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
        if(daily_readings[counter].date==NULL || daily_readings[counter].bloodIron==0)
        {
            printf("bad data\n");
            return 0;
        }
        mean += daily_readings[counter].bloodIron;
        counter++;
    }

    fclose(input);

    while (1)
    {
        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (toupper(choice))
        {
        // this allows for either capital or lower case
        case 'A':
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            break;

        case 'B':
            mean /= counter;
            printf("Your average blood iron was %.2f\n", mean);
            break;

        case 'C':
            printf("%.1f\n",find_lowest(daily_readings, counter));
            break;
        case 'D':
            printf("%.1f\n",find_highest(daily_readings, counter));
            break;
        case 'E':
            monthly_iron(daily_readings, counter);
            break;
        case 'F':
            break;
        case 'G':
            break;
        case 'Q':
            return 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}