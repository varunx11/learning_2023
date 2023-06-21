#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char grade;
} Student;

void searchStudentsByName(Student students[], int numStudents, const char* name) {
    int i, found = 0;
    
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Name: %s, Age: %d, Grade: %c\n", students[i].name, students[i].age, students[i].grade);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found with the name '%s'.\n", name);
    }
}

int main() {
    Student students[] = {
        {"John Doe", 18, 'A'},
        {"Jane Smith", 17, 'B'},
        {"John Smith", 16, 'A'},
        {"Alice Johnson", 18, 'A'}
    };
    
    int numStudents = sizeof(students) / sizeof(Student);
    const char* nameToSearch = "John Smith";
    
    searchStudentsByName(students, numStudents, nameToSearch);
    
    return 0;
}
