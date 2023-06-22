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

void extractData(const char* fileName, LogEntry* entries, int* numEntries) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    char line[MAX_LINE_LENGTH];
    *numEntries = 0;

    fgets(line, sizeof(line), file);

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

        entries[*numEntries] = entry;
        (*numEntries)++;

        if (*numEntries >= MAX_ENTRIES)
            break;  // Reached the maximum number of entries
    }

    fclose(file);
}

int main() {
    const char* fileName = "data.csv";
    LogEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    extractData(fileName, entries, &numEntries);

    // Print the extracted data
    for (int i = 0; i < numEntries; i++) {
        printf("EntryNo: %d\n", entries[i].entryNo);
        printf("SensorNo: %s\n", entries[i].sensorNo);
        printf("Temperature: %.1f\n", entries[i].temperature);
        printf("Humidity: %d\n", entries[i].humidity);
        printf("Light: %d\n", entries[i].light);
        printf("Time: %s\n", entries[i].time);
        printf("---------------------------\n");
    }

    return 0;
}
