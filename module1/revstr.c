#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);
    int i;
    char temp;
    // Swap characters from the start and the end
    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str); // Reads input string
    reverseString(str);
    printf("Reversed string is: %s\n", str);
}