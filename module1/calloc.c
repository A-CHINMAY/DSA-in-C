#include <stdio.h>
#include <stdlib.h>
int main() {
    int i = 0;
    int *ptr = NULL;
    ptr = (int *)calloc(5, sizeof(int));
    if (ptr == NULL) {
        printf("ERROR: memory allocation fail\n");
        return 1;
    }
    printf("By default values: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    for (i = 0; i < 5; i++) {
        ptr[i] = i;
    }
    printf("Entered values:");
    for (i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}