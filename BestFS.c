#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 100000 // Large value representing infinity for unconnected edges

typedef struct {
    int adjMatrix[MAX][MAX];
    int num;
    int heuristic[MAX];
} Graph;

int getMin(int heuristics[], bool visited[], int num, int current, Graph *g) {
    int min = INF;
    int minIndex = -1;
    for (int i = 0; i < num; i++) {
        if (!visited[i] && heuristics[i] < min && g->adjMatrix[current][i] > 0 && g->adjMatrix[current][i] < INF) {
            min = heuristics[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void bestFirstSearch(Graph *g, int start, int goal) {
    bool visited[MAX] = { false };
    int current = start;
    visited[start] = true;

    printf("Best-First Search Traversal: ");

    while (current != -1) {
        printf("%d ", current);

        if (current == goal) {
            printf("\nGoal node %d reached.\n", goal);
            return;
        }

        int next = getMin(g->heuristic, visited, g->num, current, g);

        if (next == -1) {
            printf("\nGoal node %d not reachable.\n", goal);
            return;
        }

        visited[next] = true;
        current = next;
    }
}

int main() {
    Graph g;
    int i, j, edges, v1, v2, weight, start, goal;

    printf("Enter the number of vertices: ");
    scanf("%d", &g.num);

    // Initialize adjacency matrix with INF for no connection
    for (i = 0; i < g.num; i++) {
        for (j = 0; j < g.num; j++) {
            g.adjMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (v1 v2 weight):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        g.adjMatrix[v1][v2] = weight;
        g.adjMatrix[v2][v1] = weight; // For undirected graph
    }

    printf("Enter heuristic values:\n");
    for (i = 0; i < g.num; i++) {
        printf("Heuristic value for vertex %d: ", i);
        scanf("%d", &g.heuristic[i]);
    }

    printf("Graph (Adjacency Matrix with Costs):\n");
    for (i = 0; i < g.num; i++) {
        for (j = 0; j < g.num; j++) {
            if (g.adjMatrix[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("Enter the goal vertex: ");
    scanf("%d", &goal);

    bestFirstSearch(&g, start, goal);

    return 0;
}


/* Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (v1 v2):
0 1
0 2
1 3
1 4
2 4
3 4
Enter heuristic values:
Heuristic value for vertex 0: 7
Heuristic value for vertex 1: 6
Heuristic value for vertex 2: 2
Heuristic value for vertex 3: 1
Heuristic value for vertex 4: 0
Graph:
0 1 1 0 0 
1 0 0 1 1 
1 0 0 0 1 
0 1 0 0 1 
0 1 1 1 0 
Enter the start vertex: 0
Enter the goal vertex: 4 */