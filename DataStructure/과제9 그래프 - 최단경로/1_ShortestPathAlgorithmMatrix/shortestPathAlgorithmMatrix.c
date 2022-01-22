#include <stdio.h>
#include <stdbool.h>
#include "shortestPathAlgorithmMatrix.h"

void dijkstra(int(*graphWeight)[INDEX], int(*shortestPathWeight)[INDEX], int startIndex, int distance[])
{
	if (startIndex < INDEX)
	{
		bool found[INDEX];

		int i, j, k;

		for (i = 0; i < INDEX; i++)
		{
			found[i] = false;
			distance[i] = INFINITY;
		}

		// 1.출발노드 설정
		found[startIndex] = true;
		distance[startIndex] = 0;

		int preIndex[INDEX], minIndex;
		int minDistance;
		for (i = 0; i < INDEX - 1; i++)
		{
			// 2. 거리를 업데이트하고 가장 가까운 노드를 찾음
			minDistance = INFINITY;
			for (j = 0; j < INDEX; j++)
			{
				if (found[j])
				{
					for (k = 0; k < INDEX; k++)
					{
						if (!found[k] && graphWeight[j][k] > 0)
						{
							if (distance[k] > distance[j] + graphWeight[j][k])
							{
								distance[k] = distance[j] + graphWeight[j][k];
								preIndex[k] = j;
							}

							if (minDistance > distance[k])
							{
								minDistance = distance[k];
								minIndex = k;
							}
						}
					}
				}
			}

			shortestPathWeight[preIndex[minIndex]][minIndex] = shortestPathWeight[minIndex][preIndex[minIndex]] = graphWeight[preIndex[minIndex]][minIndex];
			found[minIndex] = true;
		}
	}
	else
	{
		printf("Out of matrix boundary index.\n");
	}

	return;
}