#include <stdio.h>
#include <string.h>

#define MAX_DATA_LENGTH 100

struct SensorInfo {
    char sensorId[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorInfo* info) {
    char sensorId[10];
    float temperature;
    int humidity;
    int lightIntensity;

    sscanf(data, "S%[^-]-T:%f-H:%d-L:%d", sensorId, &temperature, &humidity, &lightIntensity);

    strcpy(info->sensorId, sensorId);
    info->temperature = temperature;
    info->humidity = humidity;
    info->lightIntensity = lightIntensity;
}

void printSensorInfo(struct SensorInfo* info) {
    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", info->sensorId);
    printf("Temperature: %.1f C\n", info->temperature);
    printf("Humidity: %d\n", info->humidity);
    printf("Light Intensity: %d%%\n", info->lightIntensity);
    printf("---------------------\n");
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    struct SensorInfo info;

    parseData(data, &info);
    printSensorInfo(&info);

    return 0;
}
