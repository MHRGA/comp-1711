#include <stdio.h>

int sum (int a, int b)
{
    int answer;
    answer = a + b;
    return answer;
}

float floatsum (float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main () 
{
    int y = 2;
    int z = sum(5, y);
    float a = 69.420;
    float b = floatsum(420, a);
    printf("The sum of 5 and %d is %d.\n", y, z);
    printf("The sum of 420 and %f is %f.\n", a, b);
    return 0; 
}