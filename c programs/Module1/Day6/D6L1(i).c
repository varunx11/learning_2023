#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringAndInitializeStructArray(const char* input, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;
    char temp[20];
    int count = 0;

    // Tokenize the input string based on the delimiter
    token = strtok((char*)input, delimiter);

    while (token != NULL && count < numStudents) {
        students[count].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        if (token != NULL) {
            strncpy(students[count].name, token, sizeof(students[count].name) - 1);
            students[count].name[sizeof(students[count].name) - 1] = '\0';
        }

        token = strtok(NULL, delimiter);
        if (token != NULL) {
            students[count].marks = atof(token);
        }

        count++;
    }
}

int main() {
    const char* input = "1001 Aron 100.00";
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar(); // Consume the newline character

    struct Student* students = malloc(numStudents * sizeof(struct Student));

    parseStringAndInitializeStructArray(input, students, numStudents);

    // Print the parsed structure data
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}

    return 0;
}
