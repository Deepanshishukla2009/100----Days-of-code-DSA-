#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input adjacency list
    // Format: for each vertex, number of neighbors followed by neighbors
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k); // number of neighbors

        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);

            struct Node* newNode = createNode(v);
            newNode->next = adj[i];
            adj[i] = newNode;
        }
    }

    int s;
    scanf("%d", &s); // starting vertex

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s, adj, visited);

    return 0;
}