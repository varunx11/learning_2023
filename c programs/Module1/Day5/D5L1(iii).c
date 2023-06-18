#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char* timeStr) {
    char* token;
    char* rest = strdup(timeStr);
    unsigned long totalSeconds = 0;

    // Get the hours
    token = strtok(rest, ":");
    unsigned long hours = strtoul(token, NULL, 10);
    totalSeconds += hours * 3600;

    // Get the minutes
    token = strtok(NULL, ":");
    unsigned long minutes = strtoul(token, NULL, 10);
    totalSeconds += minutes * 60;

    // Get the seconds
    token = strtok(NULL, ":");
    unsigned long seconds = strtoul(token, NULL, 10);
    totalSeconds += seconds;

    free(rest);

    return totalSeconds;
}

int main() {
    const char* time1 = "10:12:50";
    unsigned long totalSeconds1 = computeTotalSeconds(time1);
    printf("Total seconds: %lu\n", totalSeconds1);

    const char* time2 = "13:10:40";
    unsigned long totalSeconds2 = computeTotalSeconds(time2);
    printf("Total seconds: %lu\n", totalSeconds2);

    return 0;
}
