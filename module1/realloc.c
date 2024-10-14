#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr = NULL;
    int i = 0;
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("ERROR: memory allocation fail\n");
        return 1;
    }
    *ptr = 5;
    printf("Existing value:%d\n", *ptr);
    ptr = (int *)realloc(ptr, sizeof(int) * 5);
    for (i = 1; i < 5; i++) {
        ptr[i] = i;
    }
    printf("Expanded values:");
    for (i = 0; i < 5; i++) {
        printf("%d", ptr[i]);
    }
    free(ptr);
    return 0;
}