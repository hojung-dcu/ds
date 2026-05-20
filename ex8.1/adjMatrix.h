#pragma once
#define MAX_VERTEX 30

typedef struct graphType {
    int n;
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjMatrix(graphType* g);
