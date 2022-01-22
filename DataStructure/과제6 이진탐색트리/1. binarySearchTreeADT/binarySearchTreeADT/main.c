#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarySearchTreeADT.h"

#define DEBUG 0

int main()
{
	int data[] = { 14, 23, 7, 10, 33, 56, 80, 66, 70 };
	BST_TREE* bstTree = bstCreate();
	
	// 1. Insert : 성공
	for (int i = 0; i < sizeof(data) / sizeof(int); i++)
	{
		bstInsert(bstTree, data[i]);
#if DEBUG
		printf("Tree node count : %d\n", bstCount(bstTree));
#endif
	}

	// 2. Delete : 성공
	int delKey[] = { 33, 7, 14 };
	for (int i = 0; i < sizeof(delKey) / sizeof(int); i++)
	{
		bstDelete(bstTree, delKey[i]);
#if DEBUG
		printf("Tree node count : %d\n", bstCount(bstTree));
#endif
	}

	// 3. Search : 성공
	int retreiveKey[] = { 14, 23, 7 };
	for (int i = 0; i < sizeof(retreiveKey) / sizeof(int); i++)
	{
		TREE_NODE* node = bstSearch(bstTree, retreiveKey[i]);
		if (node)
		{
			printf("Key: %d, Founded: %d\n", retreiveKey[i], node->data);
		}
		else
		{
			printf("No data for key: %d\n", retreiveKey[i]);
		}
	}
#if DEBUG
	bstDelete(bstTree, 70); bstDelete(bstTree, 80); bstDelete(bstTree, 66); bstDelete(bstTree, 56); bstDelete(bstTree, 10);
	if (bstEmpty(bstTree))
		printf("empty\n");
	else printf("not empty\n");
	bstDelete(bstTree, 23);
	if (bstEmpty(bstTree))
		printf("empty\n");
	else printf("not empty\n");
#endif

	bstDestroy(bstTree);

	return 0;
}
