#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

int main() {
    struct Point p1, p2;

    printf("Enter coordinates for Point 1:\n");
    printf("x1: ");
    scanf("%f", &p1.x);
    printf("y1: ");
    scanf("%f", &p1.y);

    printf("Enter coordinates for Point 2:\n");
    printf("x2: ");
    scanf("%f", &p2.x);
    printf("y2: ");
    scanf("%f", &p2.y);

    float distance = calculateDistance(p1, p2);

    printf("Distance between Point 1(%.2f, %.2f) and Point 2(%.2f, %.2f) is: %.2f\n",
           p1.x, p1.y, p2.x, p2.y, distance);

    return 0;
}
