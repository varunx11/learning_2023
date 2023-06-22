#include <stdio.h>

int findMax(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int a = 7;
    int b = 12;
    int max = findMax(a, b);
    printf("The biggest number is: %d\n", max);
    return 0;
}
