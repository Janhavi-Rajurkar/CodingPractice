#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// BFS from given source s
void bfs(int adj[MAX][MAX], int V, int s) {
  
    // Create a queue for BFS
    int q[MAX], front = 0, rear = 0;    

    // Initially mark all the vertices as not visited
    bool visited[MAX] = { false };
    
    // Mark the source node as visited and enqueue it
    visited[s] = true;
    q[rear++] = s;
    
    // Iterate over the queue
    while (front < rear) {
      
        // Dequeue a vertex and print it
        int curr = q[front++];
        printf("%d ", curr);
        
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    } 
    printf("\n");
}

// Function to add an edge to the graph
void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;  // Undirected graph
}

int main() {
    int V, E, u, v, startVertex;

    // Take number of vertices and edges as input
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Initialize adjacency matrix
    int adj[MAX][MAX] = {0};

    // Take edges as input
    printf("Enter the edges (u v) for an undirected graph:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Take the starting vertex for BFS
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS traversal starting from the specified vertex
    printf("BFS starting from vertex %d:\n", startVertex);
    bfs(adj, V, startVertex);
    
    return 0;
}