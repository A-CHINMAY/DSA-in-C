#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr = NULL;
    int i, len = 0;
    printf("ENTER THE SIZE OF ARRAY:");
    scanf("%d", &len);
    ptr = (int *)malloc(len * sizeof(int));
    printf("ENTER THE ELEMENTS:");
    for (i = 0; i < len; i++) {
        scanf("%d", &ptr[i]);
    }
    printf("Array elements are \n");
    for (i = 0; i < len; i++) {
        printf("%d", ptr[i]);
    }
    free(ptr);
}