#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person *p1, struct Person *p2) {
    // Swap the name field
    char tempName[50];
    strcpy(tempName, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, tempName);

    // Swap the age field
    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}

int main() {
    struct Person person1, person2;

    printf("Enter details for person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);

    printf("\nEnter details for person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);

    printf("\nBefore swapping:\n");
    printf("Person 1: %s, %d years old\n", person1.name, person1.age);
    printf("Person 2: %s, %d years old\n", person2.name, person2.age);

    // Call the swapFields function to swap the fields of the two structures
    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1: %s, %d years old\n", person1.name, person1.age);
    printf("Person 2: %s, %d years old\n", person2.name, person2.age);

    return 0;
}
