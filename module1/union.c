#include <stdio.h>
union Data {
    int intValue;
    float floatValue;
};

int main() {
    union Data data;
    data.intValue = 10;
    printf("Integer: %d\n", data.intValue);
    data.floatValue = 15.5;
    printf("Float: %.2f\n", data.floatValue);
    printf("Final Integer (after float assignment): %d\n", data.intValue);
    printf("Final Float (after integer assignment): %.2f\n", data.floatValue);
}