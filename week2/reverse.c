#include <stdio.h>
int main() {
    int i;
    char input[6] = "Martin";
    for(i=5; i >= 0; i--) {
        printf("%s", input[i]);
    }
    return 0;
}