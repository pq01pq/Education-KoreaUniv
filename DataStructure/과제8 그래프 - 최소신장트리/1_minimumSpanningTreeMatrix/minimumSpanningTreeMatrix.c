#include <stdio.h>
#include <stdbool.h>
#include "minimumSpanningTreeMatrix.h"

int prim(int(*graphWeight)[INDEX], int(*mstWeight)[INDEX])
{
	bool mstNode[INDEX]; // 트리 노드의 집합. true면 트리의 노드

	int i, j, k;

	for (i = 0; i < INDEX; i++) // 모든 노드 초기화
	{
		mstNode[i] = false;
	}

	// 1. 첫 노드를 설정
	mstNode[0] = true;

	// 2. 간선과 노드을 추가해나감
	int startNode, destinationNode; // index
	int mstTotalWeight = 0; // return value
	int minWeight;
	for (i = 0; i < INDEX - 1; i++) // 추가할 간선의 수만큼 반복
	{
		minWeight = INFINITY; // 이어질 가장 짧은 간선의 가중치
		for (j = 0; j < INDEX; j++) // 간선의 시작 노드
		{
			if (mstNode[j]) // 트리에 속한 노드를 기준으로 탐색
			{
				for (k = 0; k < INDEX; k++) // 간선의 도착 노드
				{
					if (!mstNode[k] && graphWeight[j][k] > 0 && graphWeight[j][k] < minWeight) // 트리에 속하지 않은 도착노드 중 제일 가까운 도착노드를 찾음
					{
						minWeight = graphWeight[j][k];
						startNode = j;
						destinationNode = k;
					}
				}
			}
		}
		mstWeight[startNode][destinationNode] = mstWeight[destinationNode][startNode] = minWeight;
		mstNode[destinationNode] = true;
		mstTotalWeight += minWeight;
	}
	
	return mstTotalWeight;
}