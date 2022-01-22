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
		printf("X ");
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

void dijkstraUpdate(int(*w)[NODE], int* dist, bool* selected, int v)
{
	for (int i = 0; i < NODE; i++)
	{
		if (dist[i] > dist[v] + w[v][i])
		{
			dist[i] = dist[v] + w[v][i];
		}
	}
}

void dijkstra(int(*w)[NODE], int(*wd)[NODE])
{
	bool selected[NODE];
	int dist[NODE];

	for (int i = 0; i < NODE; i++)
	{
		selected[i] = false;
		dist[i] = INF;
	}

	dist[0] = 0;	// Start node

	for (int i = 0; i < NODE; i++)
	{
		int v = dijkstraGetMinVertex(dist, selected, NODE);

		if (dist[v] == INF)
		{
			return;
		}

		selected[v] = true;

		printf("selected: %d (%d)\n", v + 1, dist[v]);
		dijkstraUpdate(w, dist, selected, v);
		printArray(dist, NODE);
	}

	printArray(dist, NODE);
}

int main()
{
	int w[NODE][NODE] = {
		{0, 6, 3, INF, 9,		INF, INF, INF, INF, INF},
		{6, 0, 4, 2, INF,		INF, INF, 9, INF, INF},
		{3, 4, 0, 2, 9,			9, INF, INF, INF, INF},
		{INF, 2, 2, 0, INF,		8, INF, 9, INF, INF},
		{9, INF, 9, INF, 0,		8, INF, INF, INF, 18},
		{INF, INF, 9, 8, 8,		0, 9, 7, INF, 10},
		{INF, INF, INF, INF, INF,   9, 0, 5, 1, 3},
		{INF, 9, INF, 9, INF,	7, 5, 0, 4, INF},
		{INF, INF, INF, INF, INF,   INF, 1, 4, 0, 4},
		{INF, INF, INF, INF, 18, INF, 3, INF, 4, 0}
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