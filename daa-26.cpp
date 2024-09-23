#include <stdio.h>
#define V 4  // Number of vertices in the graph

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};  // Adjacency matrix for the graph

int colors[V];  // To store the color assigned to each vertex

// Function to check if it's safe to color the vertex with the given color
int isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && colors[i] == c) {  // Adjacent vertex has the same color
            return 0;
        }
    }
    return 1;
}

// Backtracking function to color the graph
int graphColoringUtil(int m, int v) {
    if (v == V)  // All vertices are colored
        return 1;

    for (int c = 1; c <= m; c++) {  // Try different colors
        if (isSafe(v, c)) {
            colors[v] = c;  // Assign color

            if (graphColoringUtil(m, v + 1))  // Recur for next vertex
                return 1;

            colors[v] = 0;  // Backtrack if no solution
        }
    }
    return 0;  // No solution found
}

void graphColoring(int m) {
    if (graphColoringUtil(m, 0)) {
        printf("Solution Exists: Following are the assigned colors\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d ---> Color %d\n", i, colors[i]);
    } else {
        printf("No solution exists for %d colors.\n", m);
    }
}

int main() {
    int m = 3;  // Number of colors
    graphColoring(m);
    return 0;
}

