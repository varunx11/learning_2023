#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n, i;
    struct Student *students;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' students
    students = (struct Student *)malloc(n * sizeof(struct Student));

    // Read data for each student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display data for each student
    printf("\nStudent Information:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
