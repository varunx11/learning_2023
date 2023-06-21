#include <stdio.h>
#include <string.h>

void rotateString(char* str, int k, char direction) {
    int len = strlen(str);
    k = k % len; // Adjust k to handle cases where k is greater than the length of the string
    
    if (direction == 'L' || direction == 'l') {
        // Rotate string to the left
        for (int i = 0; i < k; i++) {
            char temp = str[0];
            for (int j = 0; j < len - 1; j++) {
                str[j] = str[j + 1];
            }
            str[len - 1] = temp;
        }
    } else if (direction == 'R' || direction == 'r') {
        // Rotate string to the right
        for (int i = 0; i < k; i++) {
            char temp = str[len - 1];
            for (int j = len - 1; j > 0; j--) {
                str[j] = str[j - 1];
            }
            str[0] = temp;
        }
    }
}

int main() {
    char str[] = "abcdxyz";
    int k = 2;
    char direction = 'L';

    printf("Original String: %s\n", str);
    printf("Rotation: %d %s\n", k, (direction == 'L' || direction == 'l') ? "Left" : "Right");

    rotateString(str, k, direction);

    printf("Rotated String: %s\n", str);

    return 0;
}
