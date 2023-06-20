#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int countDays(const char* date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    int totalDays = day;

    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth[i - 1];
        if (i == 2 && isLeapYear(year)) {
            totalDays += 1; // Add an extra day for February in a leap year
        }
    }

    int years = year - 1;
    totalDays += years * 365 + years / 4 - years / 100 + years / 400;

    return totalDays;
}

int main() {
    const char* date1 = "10/04/2015";
    int days1 = countDays(date1);
    printf("Days elapsed for %s: %d\n", date1, days1);

    const char* date2 = "20/05/2017";
    int days2 = countDays(date2);
    printf("Days elapsed for %s: %d\n", date2, days2);

    const char* date3 = "31/12/1996";
    int days3 = countDays(date3);
    printf("Days elapsed for %s: %d\n", date3, days3);

    return 0;
}
