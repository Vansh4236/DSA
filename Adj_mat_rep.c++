#include <stdio.h>

#define MAX_NODES 10  // Define a maximum limit for nodes

// Function to create Adjacency Matrix
void createAdjMatrix(int N, int M, int Adj[MAX_NODES][MAX_NODES], int arr[][2]) {
    // Initialize all values in the adjacency matrix to 0
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            Adj[i][j] = 0;
        }
    }

    // Traverse the array of edges
    for (int i = 0; i < M; i++) {
        int x = arr[i][0];
        int y = arr[i][1];

        // Update adjacency matrix
        Adj[x][y] = 1;
        Adj[y][x] = 1;  // Since the graph is undirected
    }
}

// Function to print the Adjacency Matrix
void printAdjMatrix(int N, int Adj[MAX_NODES][MAX_NODES]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}

// Driver Code
int main() {
    int N = 5;  // Number of vertices

    // Given Edges
    int arr[][2] = { {1, 2}, {2, 3}, {4, 5}, {1, 5} };

    int M = sizeof(arr) / sizeof(arr[0]);  // Number of edges

    // Adjacency Matrix
    int Adj[MAX_NODES][MAX_NODES];

    // Function call to create adjacency matrix
    createAdjMatrix(N, M, Adj, arr);

    // Print adjacency matrix
    printAdjMatrix(N, Adj);

    return 0;
}
