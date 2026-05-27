#pragma once
#define MAX_VERTEX 30

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;	
	graphNode* adjList_H[MAX_VERTEX];
} graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);
