#include <stdio.h>

void swap(void *ptr1, void *ptr2, size_t size) {
    char *temp = (char *)malloc(size);
    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
    free(temp);
}

int main() {
    int a = 5;
    int b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    double c = 2.5;
    double d = 7.8;
    printf("Before swap: c = %f, d = %f\n", c, d);

    swap(&c, &d, sizeof(double));
    printf("After swap: c = %f, d = %f\n", c, d);

    return 0;
}
