#include <stdio.h>
#include <stdbool.h>
#include "minimumSpanningTreeMatrix.h"

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

	int mstWeight[INDEX][INDEX];
	int i, j;
	for (i = 0; i < INDEX; i++)
	{
		for (j = 0; j < INDEX; j++)
		{
			mstWeight[i][j] = 0;
		}
	}

	int mstTotalWeight = prim(graphWeight, mstWeight);

	printf("MST ");
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
			if (mstWeight[i][j] == 0)
				printf("  *");
			else
				printf("  %d", mstWeight[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Total weight of MST : %d\n", mstTotalWeight);

	return;
}