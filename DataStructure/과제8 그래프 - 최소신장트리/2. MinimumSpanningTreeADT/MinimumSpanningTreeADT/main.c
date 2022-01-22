#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "minimumSpanningTreeADT.h"

#define DEBUG	1

void main(void)
{
	Graph *graph = graphCreate(compareIndex);
	Graph *mstPrim = graphCreate(compareIndex);
	Graph *mstKruskal = graphCreate(compareIndex);

	// 1. Insert vertex
	int i;
	for (i = 0; i < INDEX; i++)
	{
		graphInsertVertex(graph, (element1)i, (element2)0);
	}
#if DEBUG
	Vertex *vertex;
	printf("Vertex :");
	for (i = 0; i < INDEX; i++)
	{
		vertex = searchVertex(graph, (element1)i);
		printf(" %d", (int)vertex->key);
	}
	printf("\n");
#endif
	// 2. Insert arc
	graphInsertArc(graph, (element1)0, (element1)1, 6); graphInsertArc(graph, (element1)0, (element1)2, 3); graphInsertArc(graph, (element1)0, (element1)4, 9);
	graphInsertArc(graph, (element1)1, (element1)2, 4); graphInsertArc(graph, (element1)1, (element1)3, 2); graphInsertArc(graph, (element1)1, (element1)7, 9);
	graphInsertArc(graph, (element1)2, (element1)3, 2); graphInsertArc(graph, (element1)2, (element1)4, 9); graphInsertArc(graph, (element1)2, (element1)5, 9);
	graphInsertArc(graph, (element1)3, (element1)5, 8); graphInsertArc(graph, (element1)3, (element1)7, 9);
	graphInsertArc(graph, (element1)4, (element1)5, 8); graphInsertArc(graph, (element1)4, (element1)9, 18);
	graphInsertArc(graph, (element1)5, (element1)7, 7); graphInsertArc(graph, (element1)5, (element1)6, 9); graphInsertArc(graph, (element1)5, (element1)9, 10);
	graphInsertArc(graph, (element1)6, (element1)7, 5); graphInsertArc(graph, (element1)6, (element1)8, 1); graphInsertArc(graph, (element1)6, (element1)9, 3);
	graphInsertArc(graph, (element1)7, (element1)8, 4);
	graphInsertArc(graph, (element1)8, (element1)9, 4);
#if DEBUG
	// 2-1. deletion test
	graphRemoveArc(graph, (element1)1, (element1)7);
	graphRemoveVertex(graph, (element1)0);
	graphInsertVertex(graph, (element1)0, (element2)0);
	graphInsertArc(graph, (element1)0, (element1)1, 6); graphInsertArc(graph, (element1)0, (element1)2, 3); graphInsertArc(graph, (element1)0, (element1)4, 9);
	graphInsertArc(graph, (element1)1, (element1)7, 9);
#endif
	// 3. process MST
	int mstTotalWeightKruskal = kruskal(graph, mstKruskal, INDEX);
	int mstTotalWeightPrim = prim(graph, mstPrim, INDEX);
#if DEBUG
	int sum = 0;
	vertex = mstKruskal->pFirstVertex;
	Arc *arc;
	while (vertex != NULL)
	{
		arc = vertex->pFirstArc;
		while (arc != NULL)
		{
			sum += arc->weight;
			arc = arc->pNextArc;
		}
		vertex = vertex->pNextVertex;
	}
	int averageWeight = sum / 2;

	if (mstTotalWeightKruskal == mstKruskal->totalWeight && mstKruskal->totalWeight == averageWeight)
	{
		printf("MST total weight (Kruskal): %d\n", mstKruskal->totalWeight);
	}

	sum = 0;
	vertex = mstPrim->pFirstVertex;
	while (vertex != NULL)
	{
		arc = vertex->pFirstArc;
		while (arc != NULL)
		{
			sum += arc->weight;
			arc = arc->pNextArc;
		}
		vertex = vertex->pNextVertex;
	}
	averageWeight = sum / 2;

	if (mstTotalWeightPrim == mstPrim->totalWeight && mstPrim->totalWeight == averageWeight)
	{
		printf("MST total weight (Prim): %d\n", mstPrim->totalWeight);
	}
#endif

	graphDestroy(graph);
	graphDestroy(mstKruskal);
	graphDestroy(mstPrim);

	return;
}