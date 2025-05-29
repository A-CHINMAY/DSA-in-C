#include <stdio.h>

#define MAX 10

int s[MAX], x[MAX], d;

void sumofsub(int p, int k, int r) {
    int i;
    x[k] = 1;

    if ((p + s[k]) == d) {
        for (i = 1; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", s[i]);
        }
        printf("\n");
    }
    else if ((p + s[k] + s[k + 1]) <= d) {
        sumofsub(p + s[k], k + 1, r - s[k]);
    }

    if ((p + r - s[k] >= d) && (p + s[k + 1]) <= d) {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}

int main() {
    int n, i, sum = 0;

    printf("Enter the n value: ");
    scanf("%d", &n);

    printf("Enter the set in increasing order: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    printf("Enter the max subset value: ");
    scanf("%d", &d);

    for (i = 1; i <= n; i++)
        sum += s[i];

    if (sum < d || s[1] > d) {
        printf("\nNo subset possible\n");
    }
    else {
        printf("\nSubsets with sum = %d are:\n", d);
        sumofsub(0, 1, sum);
    }

    return 0;
}
