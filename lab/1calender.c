#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;
    int date;
    char *activity;
};

struct Day create()
{
    struct Day day;
    day.name = (char *)malloc(20 * sizeof(char));      
    day.activity = (char *)malloc(100 * sizeof(char)); 
    printf("Enter the day name: ");
    scanf("%s", day.name);
    printf("Enter the date: ");
    scanf("%d", &day.date);
    printf("Enter the activity for the day: ");
    scanf(" %[^\n]", day.activity);
    return day;
}

void read(struct Day calendar[], int size) {
    for (int i = 0; i < size; i++) {
        calendar[i] = create();
    }
}

void display(struct Day calendar[], int size) {
    printf("\nWeekly Activity Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Day %d: %s\n", i + 1, calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("\n");
    }
}
int main() {
    int weekSize = 7;
    struct Day calendar[weekSize];

    read(calendar, weekSize);

    display(calendar, weekSize);

    for (int i = 0; i < weekSize; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    return 0;
}