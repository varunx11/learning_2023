#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStructArrayDescending(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStructArray(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    const int numStudents = 5;
    struct Student students[numStudents] = {
        {1001, "Aron", 85.0},
        {1002, "Bob", 92.5},
        {1003, "Charlie", 78.2},
        {1004, "David", 95.8},
        {1005, "Emily", 88.7}
    };

    printf("Before sorting:\n");
    displayStructArray(students, numStudents);

    sortStructArrayDescending(students, numStudents);

    printf("After sorting:\n");
    displayStructArray(students, numStudents);

    return 0;
}
