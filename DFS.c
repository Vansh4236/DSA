#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Graph structure
struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

// Function to initialize the graph
void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    
    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Add edge to the graph
void addEdge(struct Graph* g, int start, int end) {
    g->adj[start][end] = 1;
    g->adj[end][start] = 1;  // For undirected graph
}

// DFS function
void DFS(struct Graph* g, int visited[], int vertex) {
    printf("%d ", vertex);  // Print the visited vertex
    visited[vertex] = 1;  // Mark the vertex as visited

    // Visit all the adjacent vertices of the current vertex
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFS(g, visited, i);
        }
    }
}

int main() {
    struct Graph g;
    int visited[MAX] = {0};  // Array to keep track of visited vertices

    int vertices, edges, startVertex;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int start, end;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(&g, visited, startVertex);
    printf("\n");

    return 0;
}
