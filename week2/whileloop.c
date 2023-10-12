#include <stdio.h>

int main() {
    int a = 0;
    while (a < 5){
        printf ("a is equal to %d\n", a);
        a++;
    }
    printf ("I've finished the loop and a is equal to %d\n", a);
    int b = 1;
    int c;
    while (b < 11) {
        c = b*b;
        printf("%d\n", c);
        b++;
    }
    return 0;
}