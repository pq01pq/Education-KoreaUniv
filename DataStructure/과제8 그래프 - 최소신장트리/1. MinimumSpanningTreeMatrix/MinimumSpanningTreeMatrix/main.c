#include <stdio.h>
#include <stdbool.h>
#include "minimumSpanningTreeMatrix.h"

void printMatrix(int (*matrix)[INDEX]);

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

	int mstWeightKruskal[INDEX][INDEX], mstWeightPrim[INDEX][INDEX];
	int i, j;
	for (i = 0; i < INDEX; i++)
	{
		for (j = 0; j < INDEX; j++)
		{
			mstWeightKruskal[i][j] = 0;
			mstWeightPrim[i][j] = 0;
		}
	}

	int mstTotalWeightKruskal = kruskal(graphWeight, mstWeightKruskal);
	int mstTotalWeightPrim = prim(graphWeight, mstWeightPrim);

	printf("MST (Kruskal)\n");
	printMatrix(mstWeightKruskal);
	printf("Total weight of MST (Kruskal) : %d\n", mstTotalWeightKruskal);
	
	printf("\n");

	printf("MST (Prim)\n");
	printMatrix(mstWeightPrim);
	printf("Total weight of MST (Prim) : %d\n", mstTotalWeightPrim);

	return;
}

void printMatrix(int(*matrix)[INDEX])
{
	int i, j;

	printf("    ");
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
			if (matrix[i][j] == 0)
				printf("  *");
			else
				printf("  %d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}