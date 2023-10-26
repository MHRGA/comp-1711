#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name [20];
    char student_id [11];
    unsigned mark;
};

int main () {
    struct student new_student;
    printf("What is the mark? ");
    scanf("%u", &new_student.mark);
    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "13902178");
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}