#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Function to add an edge to the graph
void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;  // Undirected graph
}

// BFS function
void bfs(int adj[MAX][MAX], int V, int s) {
    int q[MAX], front = 0, rear = 0;
    bool visited[MAX] = { false };

    visited[s] = true;
    q[rear++] = s;

    printf("BFS traversal: ");
    while (front < rear) {
        int curr = q[front++];
        printf("%d ", curr);

        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS function
void dfs(int adj[MAX][MAX], int V, int start) {
    int stack[MAX], top = -1;
    bool visited[MAX] = { false };

    stack[++top] = start;
    visited[start] = true;

    printf("DFS traversal: ");
    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", curr);

        for (int i = V - 1; i >= 0; i--) {
            if (adj[curr][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int V, E, u, v, startVertex, choice;
    int adj[MAX][MAX] = {0};

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Input edges
    printf("Enter the edges (u v) for an undirected graph:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Menu-driven choice
    printf("\nChoose the traversal method:\n");
    printf("1. BFS\n");
    printf("2. DFS\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    switch (choice) {
        case 1:
            bfs(adj, V, startVertex);
            break;
        case 2:
            dfs(adj, V, startVertex);
            break;
        default:
            printf("Invalid choice. Please select 1 or 2.\n");
            break;
    }

    return 0;
}
