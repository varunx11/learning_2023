#include <stdio.h>

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int i, j;
    int smallestDigit = 9;
    int largestDigit = 0;

    for (i = 0; i < n; i++) {
        int num = numbers[i];
        
        while (num > 0) {
            int digit = num % 10;
            
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            
            num /= 10;
        }
    }

    if (n <= 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int numbers[] = {8, 156, 123450};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    findSmallestAndLargestDigits(n, numbers);

    return 0;
}
