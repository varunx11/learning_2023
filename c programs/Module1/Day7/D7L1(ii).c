#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void copyFile(const char *sourceFile, const char *destinationFile, char option);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Invalid number of arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    const char *option = argv[1];
    const char *sourceFile = argv[2];
    const char *destinationFile = argv[3];

    if (strcmp(option, "-s") != 0 && strcmp(option, "-l") != 0 && strcmp(option, "-u") != 0) {
        printf("Invalid option.\n");
        return 1;
    }

    copyFile(sourceFile, destinationFile, option[1]);

    return 0;
}

void copyFile(const char *sourceFile, const char *destinationFile, char option) {
    FILE *source = fopen(sourceFile, "r");
    FILE *destination = fopen(destinationFile, "w");

    if (source == NULL || destination == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), source) != NULL) {
        if (option == 'u') {
            // Convert line to uppercase
            for (int i = 0; line[i] != '\0'; i++) {
                line[i] = toupper(line[i]);
            }
        } else if (option == 'l') {
            // Convert line to lowercase
            for (int i = 0; line[i] != '\0'; i++) {
                line[i] = tolower(line[i]);
            }
        } else if (option == 's') {
            // Convert line to sentence case
            int isFirstChar = 1;
            for (int i = 0; line[i] != '\0'; i++) {
                if (isFirstChar && isalpha(line[i])) {
                    line[i] = toupper(line[i]);
                    isFirstChar = 0;
                } else if (line[i] == '.' || line[i] == '!' || line[i] == '?') {
                    isFirstChar = 1;
                } else {
                    line[i] = tolower(line[i]);
                }
            }
        }

        fputs(line, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");
}
