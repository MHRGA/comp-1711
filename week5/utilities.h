#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// declaring this value so I can use it in different places
#define buffer_size 100

/**
 * @brief Struct to hold each daily reading, contains the date as a string
 *        and the bloodIron as a floating point number.
 *
 */
typedef struct
{
    char date[20];
    float bloodIron;
} reading;

/**
 * @brief Adapted version of the tokeniseRecord function which you should now be familiar with - this one is adapted for this data file
 *        as it has fewer outputs and gives you the bloodIron as a float
 *
 * @param input the line of the file to be split
 * @param delimiter what character it should split on
 * @param date the place where the date will be stored
 * @param bloodIron the place where the bloodIron will be stored.
 */
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, float *bloodIron)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        // turns the blood iron into a float - similar to atoi().
        // we have to tell C that bloodIron is a pointer so it stores it.
        *bloodIron = atof(token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// SUGGESTED FUNCTIONS

/**
 * @brief Opens the file in the correct mode
 *
 * @param filename the name of the file to open
 * @param mode the mode (r/w/a/r+/w+/a+)
 * @return FILE* The file object to store the opened file in.
 */
FILE *open_file(char *filename, char *mode)
{
    // to do
}

/**
 * @brief Reads the data from the input file into an array of structs
 *
 * @param inputFile the open file object
 * @param dataArray the array of readings
 * @return int Returns the number of readings from the file
 */
int read_file(FILE *inputFile, reading *dataArray)
{
    // to do
}

/**
 * @brief Checks that there was data for each part of each reading in the file
 *
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return int Return 0 if there are no errors, 1 if you find an error.
 */
int data_checker(reading *dataArray, int numReadings)
{
    // to do
}


/**
 * @brief Calculates and returns the mean of the readings in the array
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The mean of the readings.
 */
float find_mean(reading* dataArray, int numReadings)
{
    // to do
}

/**
 * @brief Finds and returns the highest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The highest bloodr iron reading
 */
float find_highest(reading* dataArray, int numReadings)
{
    float highest_value;
    for (int i = 0; i < numReadings; i++)
    {
        if (i==0)
        {
            highest_value = dataArray[i].bloodIron;
        }
        if (dataArray[i].bloodIron > highest_value)
        {
            highest_value = dataArray[i].bloodIron;
        }
    }
    return highest_value;
}

/**
 * @brief Finds and returns the lowest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The lowest blood iron reading
 */
float find_lowest(reading* dataArray, int numReadings)
{
    float lowest_value;
    for (int i = 0; i < numReadings; i++)
    {
        if (i==0)
        {
            lowest_value = dataArray[i].bloodIron;
        }
        if (dataArray[i].bloodIron < lowest_value)
        {
            lowest_value = dataArray[i].bloodIron;
        }
    }
    return lowest_value;
}


/**
 * @brief Ask the user for the month to find, and then print out all readings containing that month.
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 */
void monthly_iron(reading* dataArray, int numReadings)
{
    char choice[9];
    printf("What month do you want to view? ");
    scanf("%s", choice);
    for (int i = 0; i < strlen(choice); i++)
    {
        choice[i] = toupper(choice[i]);
    }
    if(strcmp(choice, "SEPTEMBER") == 0)
    {
        char *sample = "SEP";
        for(int i = 0; i < numReadings; i++)
        {
            if(strstr(dataArray[i].date,sample) != NULL)
            {
                printf("%s - Blood iron: %.1f\n", dataArray[i].date, dataArray[i].bloodIron);
            }
        }
    }
    else if(strcmp(choice, "OCTOBER") == 0)
    {
        char *sample = "OCT";
        for(int i = 0; i < numReadings; i++)
        {
            if(strstr(dataArray[i].date,sample) != NULL)
            {
                printf("%s - Blood iron: %.1f\n", dataArray[i].date, dataArray[i].bloodIron);
            }
        }
    }
    else if(strcmp(choice, "NOVEMBER") == 0)
    {
        char *sample = "NOV";
        for(int i = 0; i < numReadings; i++)
        {
            if(strstr(dataArray[i].date,sample) != NULL)
            {
                printf("%s - Blood iron: %.1f\n", dataArray[i].date, dataArray[i].bloodIron);
            }
        }
    }
    else
    {
        printf("Invalid Choice\n");
    }
}