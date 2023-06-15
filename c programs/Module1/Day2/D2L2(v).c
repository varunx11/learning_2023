#include <stdio.h>
#include <string.h>

void encode(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        // Replace each character with a different character
        str[i] = str[i] + 1; // Simple substitution: add 1 to the ASCII value
    }
}

void decode(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        // Restore each character to its original value
        str[i] = str[i] - 1; // Subtract 1 from the ASCII value
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character

    printf("Original string: %s\n", str);

    encode(str);
    printf("Encoded string: %s\n", str);

    decode(str);
    printf("Decoded string: %s\n", str);

    return 0;
}
