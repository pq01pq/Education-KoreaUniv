#pragma once

#include <stdbool.h>

typedef void * element1;
typedef int element2;

#define MAX_INDEX	10
#define INFINITY	255
// 2^31 - 1 = 2147483647

#define INDEX		MAX_INDEX

typedef struct {
	struct vertex *pFirstVertex;
	int count;
	int totalWeight;
	int(*compare)(element1 arg1, element1 arg2);
} Graph;

typedef struct vertex {
	struct vertex *pNextVertex;
	element1 key;
	element2 data;
	int degree;
	bool processed;
	struct arc *pFirstArc;
} Vertex;

typedef struct arc {
	struct arc *pNextArc;
	struct vertex *pDestinationVertex;
	int weight;
} Arc;

Graph *graphCreate(int(*compare)(element1 arg1, element1 arg2)); // create a graph
void graphDestroy(Graph *pGraph); // destroy all vertices, arcs, and graph
bool graphInsertVertex(Graph *pGraph, element1 key, element2 data); // insert a vertex into a graph
bool graphInsertArc(Graph *pGraph, element1 key1, element1 key2, int weight); // insert an arc into a graph
bool graphRemoveVertex(Graph *pGraph, element1 key); // remove a vertex if it has no arc
bool graphRemoveArc(Graph *pGraph, element1 key1, element1 key2); // remove an arc

bool _findVertex(Graph *pGraph, Vertex **pPreVertex, Vertex **pCurVertex, element1 key);
bool _findArc(Graph *pGraph, Vertex *pVertex, Arc **pPreArc, Arc **pCurArc, element1 destinationKey);

bool _insertVertex(Graph *pGraph, Vertex *pPreVertex, Vertex *pCurVertex, element1 key, element2 data);
bool _insertArc(Graph *pGraph, Vertex *pStartVertex, Vertex *pDestinationVertex, Arc *pPreArc, Arc *pCurArc, int weight);

bool _removeVertex(Graph *pGraph, Vertex *pPreVertex, Vertex *pDelVertex);
bool _removeArc(Graph *pGraph, Vertex *pVertex, Arc *pPreArc, Arc *pDelArc);

Vertex *searchVertex(Graph *graph, element1 key);
int arcWeight(Graph *pGraph, element1 key1, element1 key2);
int compareIndex(element1 arg1, element1 arg2);

int prim(Graph *pGraph, Graph *mst, int index);
