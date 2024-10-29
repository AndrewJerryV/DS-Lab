#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* link;
} Node;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->link = NULL;
    return newNode;
}

void addEdge(Node* adjLists[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->link = adjLists[src];
    adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->link = adjLists[dest];
    adjLists[dest] = newNode;
}

void DFS(Node* adjLists[], int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = adjLists[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (visited[connectedVertex] == 0) {
            DFS(adjLists, connectedVertex, visited);
        }
        temp = temp->link;
    }
}

void BFS(Node* adjLists[], int startVertex, int visited[]) {
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->link;
        }
    }
}


int main() {
    int vertices = 8;
    Node* adjLists[MAX] = {NULL}; 
    int visited[MAX] = {0};      

    addEdge(adjLists, 0, 1);
    addEdge(adjLists, 0, 2);
    addEdge(adjLists, 0, 3);
    addEdge(adjLists, 1, 4);
    addEdge(adjLists, 1, 5);
    addEdge(adjLists, 2, 6);
    addEdge(adjLists, 3, 7);

    printf("Depth First Search: ");
    DFS(adjLists, 0, visited);

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("\nBreadth First Search: ");
    BFS(adjLists, 0, visited);

    return 0;
}
