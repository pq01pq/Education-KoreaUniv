#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "minimumSpanningTreeADT.h"

Graph *graphCreate(int(*compare)(element1 arg1, element1 arg2))
{
	Graph *pGraph = (Graph *)malloc(sizeof(Graph));

	if (pGraph)
	{
		pGraph->pFirstVertex = NULL;
		pGraph->count = 0;
		pGraph->totalWeight = 0;
		pGraph->compare = compare;
	}
	else
	{
		printf("Graph memory allocation failed.\n");
	}

	return pGraph;
}

void graphDestroy(Graph *pGraph)
{
	if (pGraph)
	{
		if (pGraph->pFirstVertex != NULL)
		{
			Vertex *pDelVertex;
			while(pGraph->pFirstVertex != NULL)
			{
				pDelVertex = pGraph->pFirstVertex;
				pGraph->pFirstVertex = pDelVertex->pNextVertex;
				if (pDelVertex->pFirstArc != NULL)
				{
					Arc *pDelArc;
					while (pDelVertex->pFirstArc != NULL)
					{
						pDelArc = pDelVertex->pFirstArc;
						pDelVertex->pFirstArc = pDelArc->pNextArc;
						free(pDelArc);
					}
				}
				free(pDelVertex);
			}
		}
		free(pGraph);
	}

	return;
}

bool graphInsertVertex(Graph *pGraph, element1 key, element2 data) // Ordered by index
{
	Vertex *pPreVertex, *pCurVertex;
	bool found = _findVertex(pGraph, &pPreVertex, &pCurVertex, key);

	if (!found)
	{
		bool vertexInserted = _insertVertex(pGraph, pPreVertex, pCurVertex, key, data);

		if (vertexInserted)
		{
			return true;
		}
	}
	else
	{
		printf("The vertex already exists.\n");
	}
	
	return false;
}

bool graphInsertArc(Graph *pGraph, element1 key1, element1 key2, int weight) // Ordered by destination index
{
	if (pGraph)
	{
		Vertex *pVertex1 = searchVertex(pGraph, key1);
		Vertex *pVertex2 = searchVertex(pGraph, key2);
		if (pVertex1 && pVertex2)
		{

			Arc *pPreArc1, *pCurArc1, *pPreArc2, *pCurArc2;
			bool found1 = _findArc(pGraph, pVertex1, &pPreArc1, &pCurArc1, key2);
			bool found2 = _findArc(pGraph, pVertex2, &pPreArc2, &pCurArc2, key1);

			if (!found1 && !found2)
			{
				bool arcInserted1 = _insertArc(pGraph, pVertex1, pVertex2, pPreArc1, pCurArc1, weight);
				bool arcInserted2 = _insertArc(pGraph, pVertex2, pVertex1, pPreArc2, pCurArc2, weight);

				if (arcInserted1 && arcInserted2)
				{
					pGraph->totalWeight += weight;
					return true;
				}
				else
				{
					if (arcInserted1 && !arcInserted2)
					{
						if (pPreArc1 == NULL)
						{
							_removeArc(pGraph, pVertex1, pPreArc1, pVertex1->pFirstArc);
						}
						else
						{
							_removeArc(pGraph, pVertex1, pPreArc1, pPreArc1->pNextArc);
						}
					}
					else if (!arcInserted1 && arcInserted2)
					{
						if (pPreArc2 == NULL)
						{
							_removeArc(pGraph, pVertex2, pPreArc2, pVertex2->pFirstArc);
						}
						else
						{
							_removeArc(pGraph, pVertex2, pPreArc2, pPreArc2->pNextArc);
						}
					}
					else if (!arcInserted1 && !arcInserted2)
					{
						;
					}
				}
			}
			else
			{
				if (found1 && !found2)
				{
					printf("Warning : Mono directional arc already exists. Direction : %d -> %d\n", (int)key1, (int)key2);
				}
				else if (!found1 && found2)
				{
					printf("Warning : Mono directional arc already exists. Direction : %d -> %d\n", (int)key2, (int)key1);
				}
				else if (found1 && found2)
				{
					printf("The arc already exists between vertex \"%d\" and vertex \"%d\"\n", (int)key1, (int)key2);
				}
			}
		}
		else
		{
			if (pVertex1 == NULL && pVertex2)
			{
				printf("The vertex does not exist. Key : %d\n", (int)key1);
			}
			else if (pVertex1 && pVertex2 == NULL)
			{
				printf("The vertex does not exist. Key : %d\n", (int)key2);
			}
			else if (pVertex1 == NULL && pVertex2 == NULL)
			{
				printf("The vertexes do not exist. Key : %d, %d\n", (int)key1, (int)key2);
			}
		}
		
	}

	return false;
}

bool graphRemoveVertex(Graph *pGraph, element1 key)
{
	if (pGraph)
	{
		Vertex *pPreVertex, *pDelVertex;
		bool found = _findVertex(pGraph, &pPreVertex, &pDelVertex, key);

		if (found)
		{
			while (pDelVertex->pFirstArc != NULL)
			{
				graphRemoveArc(pGraph, key, pDelVertex->pFirstArc->pDestinationVertex->key);
			}

			_removeVertex(pGraph, pPreVertex, pDelVertex);

			return true;
		}
		else
		{
			if (pPreVertex == NULL && pDelVertex == NULL)
			{
				printf("The graph is empty.\n");
			}
			else
			{
				printf("No vertex to remove. Key : %d\n", (int)key);
			}
		}
	}

	return false;
}

bool graphRemoveArc(Graph *pGraph, element1 key1, element1 key2)
{
	if (pGraph)
	{
		if (pGraph->pFirstVertex != NULL)
		{
			Vertex *pVertex1 = searchVertex(pGraph, key1);
			Vertex *pVertex2 = searchVertex(pGraph, key2);
			if (pVertex1 && pVertex2)
			{
				Arc *pPreArc1, *pDelArc1, *pPreArc2, *pDelArc2;

				bool found1 = _findArc(pGraph, pVertex1, &pPreArc1, &pDelArc1, key2);
				bool found2 = _findArc(pGraph, pVertex2, &pPreArc2, &pDelArc2, key1);

				if (found1 && found2)
				{
					pGraph->totalWeight -= pDelArc1->weight;

					_removeArc(pGraph, pVertex1, pPreArc1, pDelArc1);
					_removeArc(pGraph, pVertex2, pPreArc2, pDelArc2);

					return true;
				}
				else
				{
					if (found1 && !found2)
					{
						if (pPreArc2 == NULL && pDelArc2 == NULL)
						{
							printf("Vertex \"%d\" does not have any arc.\n", (int)key2);
						}

						pGraph->totalWeight -= pDelArc1->weight;
						_removeArc(pGraph, pVertex1, pPreArc1, pDelArc1);

						printf("Warning : Mono directional arc is deleted. Direction : %d -> %d\n", (int)key1, (int)key2);

						return true;
					}
					else if (!found1 && found2)
					{
						if (pPreArc1 == NULL && pDelArc1 == NULL)
						{
							printf("Vertex \"%d\" does not have any arc.\n", (int)key1);
						}

						pGraph->totalWeight -= pDelArc2->weight;
						_removeArc(pGraph, pVertex2, pPreArc2, pDelArc2);

						printf("Warning : Mono directional arc is deleted. Direction : %d -> %d\n", (int)key2, (int)key1);

						return true;
					}
					else if (!found1 && !found2)
					{
						if (pPreArc1 == NULL && pDelArc1 == NULL)
						{
							printf("Vertex \"%d\" does not have any arc.\n", (int)key1);
						}
						if (pPreArc2 == NULL && pDelArc2 == NULL)
						{
							printf("Vertex \"%d\" does not have any arc.\n", (int)key2);
						}

						printf("The arc does not exist.\n");
					}
				}
			}
			else
			{
				if (pVertex1 == NULL && pVertex2)
				{
					printf("The vertex does not exist. Key : %d\n", (int)key1);
				}
				else if (pVertex1 && pVertex2 == NULL)
				{
					printf("The vertex does not exist. Key : %d\n", (int)key2);
				}
				else if (pVertex1 == NULL && pVertex2 == NULL)
				{
					printf("The vertexes does not exist. Key : %d, %d\n", (int)key1, (int)key2);
				}
			}
		}
		else
		{
			printf("The graph is empty.\n");
		}
	}

	return false;
}

bool _findVertex(Graph *pGraph, Vertex **ppPreVertex, Vertex **ppCurVertex, element1 key)
{
	*ppPreVertex = NULL;
	*ppCurVertex = pGraph->pFirstVertex;

	if (pGraph->pFirstVertex == NULL)
	{
		return false;
	}

	int result;
	while (*ppCurVertex && (result = pGraph->compare((*ppCurVertex)->key, key)) < 0)
	{
		*ppPreVertex = *ppCurVertex;
		*ppCurVertex = (*ppCurVertex)->pNextVertex;
	}

	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool _findArc(Graph *pGraph, Vertex *pVertex, Arc **ppPreArc, Arc **ppCurArc, element1 destinationKey)
{
	*ppPreArc = NULL;
	*ppCurArc = pVertex->pFirstArc;

	if (pVertex->pFirstArc == NULL)
	{
		return false;
	}

	int result;
	while (*ppCurArc && (result = pGraph->compare((*ppCurArc)->pDestinationVertex->key, destinationKey)) < 0)
	{
		*ppPreArc = *ppCurArc;
		*ppCurArc = (*ppCurArc)->pNextArc;
	}

	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool _insertVertex(Graph *pGraph, Vertex *pPreVertex, Vertex *pCurVertex, element1 key, element2 data)
{
	Vertex *pNewVertex = (Vertex *)malloc(sizeof(Vertex));

	if (pNewVertex)
	{
		if (pPreVertex == NULL)
		{
			pNewVertex->pNextVertex = pGraph->pFirstVertex;
			pGraph->pFirstVertex = pNewVertex;
		}
		else
		{
			pNewVertex->pNextVertex = pCurVertex;
			pPreVertex->pNextVertex = pNewVertex;
		}
		pNewVertex->key = key;
		pNewVertex->data = data;
		pNewVertex->degree = 0;
		pNewVertex->processed = false;
		pNewVertex->pFirstArc = NULL;

		pGraph->count++;

		return true;
	}
	else
	{
		printf("Vertex memory allocation failed. Key : %d\n", (int)key);
	}

	return false;
}

bool _insertArc(Graph *pGraph, Vertex *pStartVertex, Vertex *pDestinationVertex, Arc *pPreArc, Arc *pCurArc, int weight)
{
	Arc *pNewArc = (Arc *)malloc(sizeof(Arc));

	if (pNewArc)
	{
		if (pPreArc == NULL)
		{
			pNewArc->pNextArc = pStartVertex->pFirstArc;
			pStartVertex->pFirstArc = pNewArc;
		}
		else
		{
			pNewArc->pNextArc = pCurArc;
			pPreArc->pNextArc = pNewArc;
		}

		pNewArc->pDestinationVertex = pDestinationVertex;
		pNewArc->weight = weight;

		pStartVertex->degree++;

		return true;
	}
	else
	{
		printf("Arc memory allocation failed. Direction : %d -> %d\n", (int)pStartVertex->key, (int)pDestinationVertex->key);
	}

	return false;
}

bool _removeVertex(Graph *pGraph, Vertex *pPreVertex, Vertex *pDelVertex)
{
	if (pGraph)
	{
		if (pPreVertex == NULL)
		{
			pGraph->pFirstVertex = pDelVertex->pNextVertex;
		}
		else
		{
			pPreVertex->pNextVertex = pDelVertex->pNextVertex;
		}

		pGraph->count--;

		free(pDelVertex);

		return true;
	}

	return false;
}

bool _removeArc(Graph *pGraph, Vertex *pVertex, Arc *pPreArc, Arc *pDelArc)
{
	if (pGraph)
	{
		if (pVertex)
		{
			if (pPreArc == NULL)
			{
				pVertex->pFirstArc = pDelArc->pNextArc;
			}
			else
			{
				pPreArc->pNextArc = pDelArc->pNextArc;
			}

			pVertex->degree--;

			free(pDelArc);

			return true;
		}
	}

	return false;
}

Vertex *searchVertex(Graph *pGraph, element1 key) // Operate on both ordered and unordered vertex list
{
	if (pGraph)
	{
		if (pGraph->pFirstVertex)
		{
			Vertex *pVertex = pGraph->pFirstVertex;
			while (pVertex && pGraph->compare(pVertex->key, key) != 0)
			{
				pVertex = pVertex->pNextVertex;
			}

			if (pVertex)
			{
				return pVertex;
			}
			else
			{
				printf("The vertex does not exist. Key : %d\n", (int)key);
			}
		}
		else
		{
			printf("The graph is empty.\n");
		}
	}

	return NULL;
}

int arcWeight(Graph *graph, element1 key1, element1 key2)
{
	if (graph)
	{
		Vertex *pVertex1 = searchVertex(graph, key1);
		Vertex *pVertex2 = searchVertex(graph, key2);
		if (pVertex1 && pVertex2)
		{
			Arc *pArc1 = pVertex1->pFirstArc;
			Arc *pArc2 = pVertex2->pFirstArc;
			while (pArc1 && graph->compare(key2, pArc1->pDestinationVertex->key) != 0)
			{
				pArc1 = pArc1->pNextArc;
			}
			while (pArc2 && graph->compare(key1, pArc2->pDestinationVertex->key) != 0)
			{
				pArc2 = pArc2->pNextArc;
			}

			if (pArc1 && pArc2)
			{
				if (pArc1->weight == pArc2->weight)
				{
					return pArc1->weight;
				}
				else
				{
					printf("Error : Arc weight does not match with its twin arc.\n");
				}
			}
			else
			{
				if (pArc1 && pArc2 == NULL)
				{
					printf("Error : Mono directional arc. Direction : %d -> %d\n", (int)key1, (int)key2);
				}
				else if (pArc1 == NULL && pArc2)
				{
					printf("Error : Mono directional arc. Direction : %d -> %d\n", (int)key2, (int)key1);
				}
				else if (pArc1 == NULL && pArc2 == NULL)
				{
					; // 간선이 없으면 0을 리턴
				}
			}
		}
	}

	return 0;
}

int compareIndex(element1 arg1, element1 arg2)
{
	return (int)arg1 - (int)arg2;
}

int prim(Graph *graph, Graph *mst, int index)
{
	int i, j, k;

	// 1. 첫 노드를 설정
	Vertex *vertex0 = searchVertex(graph, (element1)0);
	graphInsertVertex(mst, (element1)0, (element2)0);
	vertex0->processed = true;

	// 2. 간선과 노드을 추가해나감
	Vertex *jNode, *kNode; // 출발 노드와 도착 노드
	Vertex *node1 = NULL, *node2 = NULL; // 간선의 양쪽 노드
	int mstTotalWeight = 0; // return value
	int minWeight;
	int edgeWeight;
	for (i = 0; i < index - 1; i++) // 추가할 간선의 수만큼 반복
	{
		minWeight = INFINITY; // 이어질 가장 짧은 간선의 가중치
		for (j = 0; j < index; j++) // 간선의 시작 노드
		{
			jNode = searchVertex(graph, (element1)j);
			if (jNode->processed) // 트리에 속한 노드를 기준으로 탐색
			{
				for (k = 0; k < index; k++) // 간선의 도착 노드
				{
					kNode = searchVertex(graph, (element1)k);
					edgeWeight = arcWeight(graph, (element1)j, (element1)k);
					if (!kNode->processed && edgeWeight > 0 && edgeWeight < minWeight) // 트리에 속하지 않은 도착노드 중 제일 가까운 도착노드를 찾음
					{
						minWeight = edgeWeight;
						node1 = jNode;
						node2 = kNode;
					}
				}
			}
		}
		graphInsertVertex(mst, node2->key, (element2)0);
		graphInsertArc(mst, node1->key, node2->key, minWeight);
		node2->processed = true;
		mstTotalWeight += minWeight;
	}

	return mstTotalWeight;
}