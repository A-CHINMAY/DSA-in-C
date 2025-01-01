#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int a[MAX][MAX], visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, i;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (i = 1; i <= n; i++) {
            if (a[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;
    for (i = 1; i <= n; i++) {
        if (a[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int ch, start, i, j;
    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while (1) {
        for (i = 1; i <= n; i++) {
            visited[i] = 0;
        }
        printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
        printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
        printf("\n==>3: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\nEnter the starting vertex: ");
            scanf("%d", &start);
            printf("\nNodes reachable from starting vertex %d are: ", start);
            bfs(start);
            for (i = 1; i <= n; i++) {
                if (visited[i] == 0) {
                    printf("\nThe vertex that is not reachable is %d", i);
                }
            }
            break;
        case 2:
            printf("\nEnter the starting vertex: ");
            scanf("%d", &start);
            printf("\nNodes reachable from starting vertex %d are:\n", start);
            dfs(start);
            break;
        case 3:
            exit(0);
        default:
            printf("\nPlease enter a valid choice.");
        }
    }
    return 0;
}