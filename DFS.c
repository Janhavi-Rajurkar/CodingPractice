#include<stdio.h>
#include<stdbool.h>
#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void dfs(int adj[MAX_VERTICES][MAX_VERTICES], int V, int start){
    int stack[MAX_VERTICES];
    int top=-1;

    bool visited[MAX_VERTICES] = {false};

    stack[++top] = start;
    visited[start] = true;

    printf("DFS travsersal: ");

    while(top != -1){
        int curr = stack[top--];
        printf("%d ", curr);

        for(int i=V-1; i>=0; i--){
            if(adj[curr][i] == 1 && !visited[i]){
                stack[++top] = i;
                visited[i] = true;
            }
        }
    } 
}

int main(){
    int V, E, u, v, start;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d",&E);

    for(int i=0; i<E; i++){
        printf("Enter the edge %d: ",i+1);
        scanf("%d", &u);
        scanf("%d", &v);
        addEdge(adj, u, v);
    }

    printf("Enter the start vertex: \n");
    scanf("%d",&start);    

    dfs(adj, V, start);

    return 0;
}