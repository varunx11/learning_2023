#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float physicsMarks, mathMarks, chemistryMarks;
    float totalMarks, percentage;

    
    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);

    
    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    
    printf("Enter Marks in Physics: ");
    scanf("%f", &physicsMarks);
    printf("Enter Marks in Math: ");
    scanf("%f", &mathMarks);
    printf("Enter Marks in Chemistry: ");
    scanf("%f", &chemistryMarks);

    
    totalMarks = physicsMarks + mathMarks + chemistryMarks;
    percentage = (totalMarks / 300) * 100;

    
    printf("\n------ Summary ------\n");
    printf("Roll Number: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", physicsMarks);
    printf("Math Marks: %.2f\n", mathMarks);
    printf("Chemistry Marks: %.2f\n", chemistryMarks);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
