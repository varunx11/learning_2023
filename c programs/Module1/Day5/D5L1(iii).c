#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTime();
void displayTime(struct Time t);
struct Time calculateDifference(struct Time start, struct Time end);

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time:\n");
    startTime = getTime();

    printf("\nEnter the end time:\n");
    endTime = getTime();

    difference = calculateDifference(startTime, endTime);

    printf("\nDifference between the two time periods:\n");
    displayTime(difference);

    return 0;
}

struct Time getTime() {
    struct Time t;

    printf("Enter hours: ");
    scanf("%d", &t.hours);

    printf("Enter minutes: ");
    scanf("%d", &t.minutes);

    printf("Enter seconds: ");
    scanf("%d", &t.seconds);

    return t;
}

void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

struct Time calculateDifference(struct Time start, struct Time end) {
    struct Time diff;

    // Convert both start and end times to seconds
    int startTimeInSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int endTimeInSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;

    int differenceInSeconds = endTimeInSeconds - startTimeInSeconds;

    // Calculate hours, minutes, and seconds from the difference in seconds
    diff.hours = differenceInSeconds / 3600;
    differenceInSeconds %= 3600;

    diff.minutes = differenceInSeconds / 60;
    differenceInSeconds %= 60;

    diff.seconds = differenceInSeconds;

    return diff;
}
