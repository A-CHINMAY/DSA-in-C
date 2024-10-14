#include <stdio.h>
struct Employee {
    char Ename[50];
    int Empid;
    struct {
        int day;
        int month;
        int year;
    } DOB;
    struct {
        float Basic;
        float DA;  // Dearness Allowance
        float HRA; // House Rent Allowance
    } salary;
};

int main() {
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);

        printf("Enter Name: ");
        scanf("%s", emp[i].Ename);

        printf("Enter Employee ID: ");
        scanf("%d", &emp[i].Empid);

        printf("Enter Date of Birth (day month year): ");
        scanf("%d %d %d", &emp[i].DOB.day, &emp[i].DOB.month, &emp[i].DOB.year);

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[i].salary.Basic);

        printf("Enter DA (Dearness Allowance): ");
        scanf("%f", &emp[i].salary.DA);

        printf("Enter HRA (House Rent Allowance): ");
        scanf("%f", &emp[i].salary.HRA);
    }

    printf("\nEmployee Information:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", emp[i].Ename);
        printf("Employee ID: %d\n", emp[i].Empid);
        printf("Date of Birth: %02d/%02d/%04d\n", emp[i].DOB.day, emp[i].DOB.month, emp[i].DOB.year);
        printf("Basic Salary: %.2f\n", emp[i].salary.Basic);
        printf("DA (Dearness Allowance): %.2f\n", emp[i].salary.DA);
        printf("HRA (House Rent Allowance): %.2f\n", emp[i].salary.HRA);
    }
}
