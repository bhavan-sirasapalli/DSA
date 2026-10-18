#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int cost[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);

        if (u == -1 || dist[u] == INF) {
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != 0 && dist[u] != INF 
                && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest Distances from Source City %d\n", src);
    printf("Destination City\tMinimum Travel Cost\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d\t\t\tUnreachable\n", i);
        } else {
            printf("%d\t\t\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int n, src;
    int cost[MAX][MAX];

    printf("Enter number of cities/vertices (n >= 5): ");
    scanf("%d", &n);
    if (n < 5 || n > MAX) {
        printf("Invalid input. Please enter between 5 and %d vertices.\n", MAX);
        return 1;
    }

    printf("Enter the Weighted Adjacency Matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source city (0 to %d): ", n - 1);
    scanf("%d", &src);
    if (src < 0 || src >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(cost, n, src);

    return 0;
}