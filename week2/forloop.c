#include <stdio.h>

int main() {
    int a;
    for (a = 0; a < 5; a++) {
        printf ("a is equal to %d\n", a);
    }
    printf ("I've finished the loop and a is equal to %d\n", a);
    int b;
    for (b = 1; b < 21; b+=2) {
        printf("%d\n", b);
    }
    int c;
    for (c = 20; c > 0; c-=2) {
        printf("%d\n", c);
    }
    return 0;
}