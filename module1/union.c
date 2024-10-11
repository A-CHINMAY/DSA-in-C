#include <stdio.h>

// Define a union with int and float
union Data
{
    int intValue;
    float floatValue;
};

int main()
{
    // Create a union variable
    union Data data;

    // Assign an integer value
    data.intValue = 10;
    printf("Integer: %d\n", data.intValue);

    // Assign a float value
    data.floatValue = 15.5;
    printf("Float: %.2f\n", data.floatValue);

    // Note: Only the last assigned value is valid to use
    printf("Final Integer (after float assignment): %d\n", data.intValue);
    printf("Final Float (after integer assignment): %.2f\n", data.floatValue);

    return 0;
}