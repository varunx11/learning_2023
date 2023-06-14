#include <stdio.h>

int findMax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a = 10;
    int b = 20;
    int max = findMax(a, b);
    printf("The maximum number is: %d\n", max);
    return 0;
}
