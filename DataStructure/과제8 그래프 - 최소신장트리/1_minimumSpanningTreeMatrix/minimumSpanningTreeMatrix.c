#include <stdio.h>
#include <stdbool.h>
#include "minimumSpanningTreeMatrix.h"

int prim(int(*graphWeight)[INDEX], int(*mstWeight)[INDEX])
{
	bool mstNode[INDEX]; // Ʈ�� ����� ����. true�� Ʈ���� ���

	int i, j, k;

	for (i = 0; i < INDEX; i++) // ��� ��� �ʱ�ȭ
	{
		mstNode[i] = false;
	}

	// 1. ù ��带 ����
	mstNode[0] = true;

	// 2. ������ ����� �߰��س���
	int startNode, destinationNode; // index
	int mstTotalWeight = 0; // return value
	int minWeight;
	for (i = 0; i < INDEX - 1; i++) // �߰��� ������ ����ŭ �ݺ�
	{
		minWeight = INFINITY; // �̾��� ���� ª�� ������ ����ġ
		for (j = 0; j < INDEX; j++) // ������ ���� ���
		{
			if (mstNode[j]) // Ʈ���� ���� ��带 �������� Ž��
			{
				for (k = 0; k < INDEX; k++) // ������ ���� ���
				{
					if (!mstNode[k] && graphWeight[j][k] > 0 && graphWeight[j][k] < minWeight) // Ʈ���� ������ ���� ������� �� ���� ����� ������带 ã��
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