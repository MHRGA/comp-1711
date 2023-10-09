#include <stdio.h>
int main() {
    float a, b, c;
    printf("Please enter the length: ");
    scanf("%f", &a);
    printf("Please enter the width: ");
    scanf("%f", &b);
    c = a * b;
    printf("The area of your rectangle is %f \n", c);
    return 0;
}