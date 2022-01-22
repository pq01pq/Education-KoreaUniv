#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTreeADT.h"
#include "stackADT.h"

void dfs(TREE_NODE* rootNode)
{
	TREE_NODE* root = rootNode;
	STACK* stack = createStack();
	pushStack(stack, root);

	while (stack->top != NULL)
	{
			printf("%s\n", root->data);
			if (hasChild(root))
			{
				if (root->left != NULL) {
					pushStack(stack, root);
					root = root->left;
				}
				else {
					if (root->right != NULL) {
						pushStack(stack, root);
						root = root->right;
					}
					else
					{
						root = popStack(stack);
					}
				}
			}
			else
			{
				root = popStack(stack);
			}
	}
}

int main()
{
	TREE_NODE* bt = buildDummyTree();

	dfs(bt);

	return 0;
}
