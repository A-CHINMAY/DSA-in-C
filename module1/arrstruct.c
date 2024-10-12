#include <stdio.h>
struct student {
    char name[50];
    float marks;
};

int main() {
    int i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student students[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nStudent Names and Marks:\n");
    for (i = 0; i < n; i++){
        printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
    }
}