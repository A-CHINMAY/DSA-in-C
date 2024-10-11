#include <stdio.h>

// Define a structure
struct Person
{
    char name[50];
    int age;
};

int main()
{
    struct Person person1;

    // Assign values to the structure members
    printf("Enter name: ");
    scanf("%s", &person1.name);
    printf("Enter age: ");
    scanf("%d", &person1.age);

    // Access and print the structure members
    printf("\nName: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    return 0;
}