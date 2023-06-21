#include <stdio.h>

// Define the structure for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of a box using structure pointer
double calculateVolume(struct Box *boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

// Function to calculate the total surface area of a box using structure pointer
double calculateSurfaceArea(struct Box *boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->width * boxPtr->height + boxPtr->height * boxPtr->length);
}

int main() {
    // Create a box object
    struct Box myBox = { 5.0, 3.0, 4.0 };

    // Create a pointer to the box object
    struct Box *boxPtr = &myBox;

    // Calculate volume using structure pointer and indirection operator
    double volume = calculateVolume(boxPtr);

    // Calculate surface area using structure pointer and indirection operator
    double surfaceArea = calculateSurfaceArea(boxPtr);

    // Print the results
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
