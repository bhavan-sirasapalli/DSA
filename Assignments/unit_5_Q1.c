#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void BFS(int adj[MAX][MAX], int n, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    printf("BFS Visit Order: ");

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS_util(int adj[MAX][MAX], int n, int vertex, int visited[]) {
    visited[vertex] = 1;            
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS_util(adj, n, i, visited);
        }
    }
}

void DFS(int adj[MAX][MAX], int n, int startVertex) {
    int visited[MAX] = {0};
    printf("DFS Visit Order: ");
    DFS_util(adj, n, startVertex, visited);
    printf("\n");
}

int main() {
    int n, startVertex;
    int adj[MAX][MAX];

    printf("Enter number of locations/vertices (n): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the Adjacency Matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    if (scanf("%d", &startVertex) != 1 || startVertex < 0 || startVertex >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    printf("\nTraversals: \n", startVertex);
    BFS(adj, n, startVertex);
    DFS(adj, n, startVertex);

    return 0;
}