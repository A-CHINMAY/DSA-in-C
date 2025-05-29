#include <stdio.h>
#define INF 999

int prim(int c[10][10], int n, int s) {
    int v[10], ver[10], d[10], i, j, u, min, sum = 0;

    for (i = 1; i <= n; i++) {
        ver[i] = s;
        d[i] = c[s][i];
        v[i] = 0;
    }

    v[s] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 1; j <= n; j++) {
            if (!v[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;
        sum += d[u];

        printf("%d -> %d, weight = %d\n", ver[u], u, d[u]);

        for (j = 1; j <= n; j++) {
            if (!v[j] && c[u][j] < d[j]) {
                d[j] = c[u][j];
                ver[j] = u;
            }
        }
    }

    return sum;
}

int main() {
    int c[10][10], i, j, res, n, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &s);

    res = prim(c, n, s);
    printf("Total cost of minimum spanning tree: %d\n", res);

    return 0;
}
