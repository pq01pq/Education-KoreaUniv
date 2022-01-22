#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NODE 10
#define INF 0x7FFF

typedef struct 
{
	int u;
	int v;
	int w;
}EDGE;

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

/* KRUSKAL */
EDGE kruskalGetMin(int(*w)[NODE], int* groups)
{
	int min = INT_MAX;
	EDGE edge;
	edge.w = INF;

	for (int i = 0; i < NODE; i++)
	{
		for (int j = 0; j < NODE; j++)
		{
			if (w[i][j] < min && groups[i] != groups[j])
			{
				min = w[i][j];
				edge.u = i;
				edge.v = j;
				edge.w = w[i][j];
			}
		}
	}

	return edge;
}

void kruskalUnionGroup(int* groups, int g1, int g2, size_t size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (groups[i] == g2)
		{
			groups[i] = g1;
		}
	}
}

void kruskalUpdate(int* groups, int u, int v, size_t size)
{
	kruskalUnionGroup(groups, groups[u], groups[v], size);
}

void kruskal(int (*w)[NODE], int(*wk)[NODE])
{
	int groups[NODE];

	for (int i = 0; i < NODE; i++)
	{
		groups[i] = i;
	}

	for (int i = 0; i < NODE; i++)
	{
		EDGE edge = kruskalGetMin(w, groups);

		if (edge.w == INF)
		{
			return;
		}

		wk[edge.u][edge.v] = wk[edge.v][edge.u] = w[edge.u][edge.v];
		kruskalUpdate(groups, edge.u, edge.v, NODE);

		printf("%d-%d (%d)\n", edge.u + 1, edge.v + 1, edge.w);
		/*for (int j = 0; j < NODE; j++)
		{
			printf("%d ", groups[j]);
		}
		printf("\n");*/
	}
}

/* PRIM */
int primGetMinVertex(int* dist, bool* selected, int size)
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

void primUpdate(int (*w)[NODE], int* dist, int* last, bool* selected, int v)
{
	for (int i = 0; i < NODE; i++)
	{
		if (!selected[i] && w[v][i] != INF && dist[i] > w[v][i])
		{
			dist[i] = w[v][i];
			last[i] = v;
		}
	}
}

void prim(int (*w)[NODE], int (*wp)[NODE])
{
	bool selected[NODE];
	int dist[NODE];
	int last[NODE];

	for (int i = 0; i < NODE; i++)
	{
		selected[i] = false;
		dist[i] = INF;
		last[i] = -1;
	}

	dist[0] = 0;

	for (int i = 0; i < NODE; i++)
	{
		int v = primGetMinVertex(dist, selected, NODE);

		if (dist[v] == INF)
		{
			return;
		}

		selected[v] = true;
		if (last[i] >= 0)
		{
			int u = last[v];
			wp[u][v] = wp[v][u] = w[u][v];
		}
		
		primUpdate(w, dist, last, selected, v);
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

	int wk[NODE][NODE]; // for kruksal
	int wp[NODE][NODE];	// for prim
	for (int i = 0; i < NODE; i++)
	{
		for (int j = 0; j < NODE; j++)
		{
			wk[i][j] = INF;
			wp[i][j] = INF;
		}
	}

	printf("//////////////////////////////\nKruskal: \n");
	kruskal(w, wk);
	printf("------------------------------\n");
	printWeight(wk);

	printf("//////////////////////////////\nPrim: \n");
	prim(w, wp);
	printf("------------------------------\n");
	printWeight(wp);

	return 0;
}