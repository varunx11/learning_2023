#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

void swap(LogEntry* a, LogEntry* b) {
    LogEntry temp = *a;
    *a = *b;
    *b = temp;
}

void sortDataByTemperature(const char* fileName) {
    FILE* file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    LogEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    // Read data from file
    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file);  // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';  // Remove newline character

        char* token = strtok(line, ",");
        if (token == NULL)
            continue;  // Skip empty lines

        LogEntry entry;
        entry.entryNo = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;

        strncpy(entry.sensorNo, token, sizeof(entry.sensorNo) - 1);
        entry.sensorNo[sizeof(entry.sensorNo) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;

        entry.temperature = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;

        entry.humidity = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;

        entry.light = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;

        strncpy(entry.time, token, sizeof(entry.time) - 1);
        entry.time[sizeof(entry.time) - 1] = '\0';

        entries[numEntries] = entry;
        numEntries++;

        if (numEntries >= MAX_ENTRIES)
            break;  // Reached the maximum number of entries
    }

    // Perform sorting by temperature in descending order
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = 0; j < numEntries - i - 1; j++) {
            if (entries[j].temperature < entries[j + 1].temperature) {
                swap(&entries[j], &entries[j + 1]);
            }
        }
    }

    // Rewriting sorted data back to the file
    rewind(file);  // Move the file pointer to the beginning

    // Write the header line
    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,\n");

    // Write sorted data
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n", entries[i].entryNo, entries[i].sensorNo,
                entries[i].temperature, entries[i].humidity, entries[i].light, entries[i].time);
    }

    fclose(file);
}

int main() {
    const char* fileName = "data.csv";
