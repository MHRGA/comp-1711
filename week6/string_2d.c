#include <stdio.h>
#include <string.h>

void readNames(char Names[][30], int maxNames) {
    int numNames;
    printf("Enter the number of names (up to %d): ", maxNames);
    scanf("%d", &numNames);
    while (getchar() != '\n') {
    }
    for (int i = 0; i < numNames; i++) {
        printf("Enter full name %d (First Last): ", i + 1);
        fgets(Names[i], 30, stdin);
        Names[i][strcspn(Names[i], "\n")] = '\0';
    }
}

int main() {
    int maxNames = 5;
    char Names[maxNames][30];
    readNames(Names, maxNames);
    printf("Entered names:\n");
    for (int i = 0; i < maxNames; i++) {
        printf("%s\n", Names[i]);
    }
    return 0;
}