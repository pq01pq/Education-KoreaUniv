#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NODE 10
#define INF 0x7FFF

inline void printINForVAL(int val)
{
	if (val == INF)
	{
		printf("* ");
	}
	else
	{
		printf("%d ", val);
	}
}

void printArray(int* data, size_t size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		printINForVAL(data[i]);
	}
	printf("\n");
}

void printWeight(int(*w)[NODE])
{
	for (int i = 0; i < NODE; i++)
	{
		for (int j = 0; j < NODE; j++)
		{
			printINForVAL(w[i][j]);
		}
		printf("\n");
	}
}

/* DIJKSTRA */
int dijkstraGetMinVertex(int* dist, bool* selected, int size)
{
	int min = INT_MAX;
	int v = -1;

	for (int i = 0; i < size; i++)
	{
		if (!selected[i] && dist[i] < min)
		{
			min = dist[i];
			v = i;
		}
	}

	return v;
}

void dijkstraUpdate(int(*w)[NODE], int* dist, int* preNode, bool* selected, int v)
{
	for (int i = 0; i < NODE; i++)
	{
		if (!selected[i] && dist[i] > dist[v] + w[v][i])
		{
			dist[i] = dist[v] + w[v][i];
			preNode[i] = v;
		}
	}
}

void dijkstra(int(*w)[NODE], int(*wd)[NODE])
{
	bool selected[NODE];
	int dist[NODE];
	int preNode[NODE];

	for (int i = 0; i < NODE; i++)
	{
		selected[i] = false;
		dist[i] = INF;
		preNode[i] = -1;
	}

	dist[0] = 0;	// Start node
	int v = 0;
	printf("selected: %d (%d)\n", v + 1, dist[v]);
	selected[0] = true;
	dijkstraUpdate(w, dist, preNode, selected, v);

	for (int i = 0; i < NODE - 1; i++)
	{
		v = dijkstraGetMinVertex(dist, selected, NODE);
		
		if (dist[v] == INF)
		{
			return;
		}

		printf("selected: %d (%d)\n", v + 1, dist[v]);
		selected[v] = true;
		
		wd[v][preNode[v]] = wd[preNode[v]][v] = w[v][preNode[v]];
		
		dijkstraUpdate(w, dist, preNode, selected, v);
		printArray(dist, NODE);
	}

	printArray(dist, NODE);
}

int main()
{
	int w[NODE][NODE] = {
		{INF, 6, 3, INF, 9,		INF, INF, INF, INF, INF},
		{6, INF, 4, 2, INF,		INF, INF, 9, INF, INF},
		{3, 4, INF, 2, 9,			9, INF, INF, INF, INF},
		{INF, 2, 2, INF, INF,		8, INF, 9, INF, INF},
		{9, INF, 9, INF, INF,		8, INF, INF, INF, 18},
		{INF, INF, 9, 8, 8,		INF, 9, 7, INF, 10},
		{INF, INF, INF, INF, INF,   9, INF, 5, 1, 3},
		{INF, 9, INF, 9, INF,	7, 5, INF, 4, INF},
		{INF, INF, INF, INF, INF,   INF, 1, 4, INF, 4},
		{INF, INF, INF, INF, 18, 10, 3, INF, 4, INF}
	};

	int wd[NODE][NODE];
	for (int i = 0; i < NODE; i++)
	{
		for (int j = 0; j < NODE; j++)
		{
			wd[i][j] = INF;
		}
	}

	printf("//////////////////////////////\nDijkstra: \n");
	dijkstra(w, wd);
	printf("------------------------------\n");
	printWeight(wd);

	return 0;
}