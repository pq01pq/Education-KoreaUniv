#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "shortestPathAlgorithmMatrix.h"

void main(void)
{
#if TEST
	int graphWeight[TEST_INDEX][TEST_INDEX] =
	{
		{0, 1, 4, 2, 3},
		{1, 0, 2, 0, 3},
		{4, 2, 0, 1, 0},
		{2, 0, 1, 0, 2},
		{3, 3, 0, 2, 0}
	};
#else
	int graphWeight[MAX_INDEX][MAX_INDEX] = {
		/*	0	1	2	3	4	5	6	7	8	9	*/
/* 0 */{	0,	6,	3,	0,	9,	0,	0,	0,	0,	0	},
/* 1 */{	6,	0,	4,	2,	0,	0,	0,	9,	0,	0	},
/* 2 */{	3,	4,	0,	2,	9,	9,	0,	0,	0,	0	},
/* 3 */{	0,	2,	2,	0,	0,	8,	0,	9,	0,	0	},
/* 4 */{	9,	0,	9,	0,	0,	8,	0,	0,	0,	18	},
/* 5 */{	0,	0,	9,	8,	8,	0,	9,	7,	0,	10	},
/* 6 */{	0,	0,	0,	0,	0,	9,	0,	5,	1,	3	},
/* 7 */{	0,	9,	0,	9,	0,	7,	5,	0,	4,	0	},
/* 8 */{	0,	0,	0,	0,	0,	0,	1,	4,	0,	4	},
/* 9 */{	0,	0,	0,	0,	18,	10, 3,	0,	4,	0	}
	};
#endif

	int shortestPathWeight[INDEX][INDEX];
	int i, j;
	for (i = 0; i < INDEX; i++)
	{
		for (j = 0; j < INDEX; j++)
		{
			shortestPathWeight[i][j] = 0;
		}
	}

	char s[3];
	printf("Shortest path algorithm by Dijkstra\n");
	printf("Start index (0 ~ %d): ", INDEX - 1);
	scanf("%s", s);
	printf("\n");
	int startIndex = atoi(s);
	int distance[INDEX];

	dijkstra(graphWeight, shortestPathWeight, startIndex, distance);

	if (startIndex < INDEX)
	{
		printf("Shortest path matrix :\n    ");
		for (i = 0; i < INDEX; i++)
		{
			printf("[%d]", i);
		}
		printf("\n");
		for (i = 0; i < INDEX; i++)
		{
			printf("[%d]", i);
			for (j = 0; j < INDEX; j++)
			{
				if (shortestPathWeight[i][j] == 0)
					printf("  *");
				else if (shortestPathWeight[i][j] > 9)
					printf(" %d", shortestPathWeight[i][j]);
				else
					printf("  %d", shortestPathWeight[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for (i = 0; i < INDEX; i++)
		{
			if (i != startIndex)
				printf("Distance from %d(start) to %d : %d\n", startIndex, i, distance[i]);
		}
	}

	return;
}