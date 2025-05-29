#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i, j;
    float weight[50], profit[50], ratio[50];
    float capacity, Totalvalue = 0.0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d]: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i]; // Profit-to-weight ratio
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(&ratio[i], &ratio[j]);
                swap(&weight[i], &weight[j]);
                swap(&profit[i], &profit[j]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
        else {
            Totalvalue += ratio[i] * capacity; 
            break;                             
        }
    }

    printf("The maximum value is: %.2f\n", Totalvalue);
    return 0;
}
