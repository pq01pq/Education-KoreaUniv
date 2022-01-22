#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "binarySearchTreeADT.h"

BST_TREE* bstCreate()
{
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	if (tree)
	{
		tree->root = NULL;
		tree->count = 0;
	}

	return tree;
}

void bstDestroy(BST_TREE* tree)
{
	if (tree)
	{
		_bstDestroy(tree->root);
		tree->count = 0;

		free(tree);
	}
}

void _bstDestroy(TREE_NODE* root)
{
	if (root)
	{
		_bstDestroy(root->left);
		_bstDestroy(root->right);
		free(root);
	}
}

bool bstInsert(BST_TREE* tree, int data)
{

}

bool bstDelete(BST_TREE* tree, int key)
{

}

TREE_NODE* bstSearch(BST_TREE* tree, int key)
{

}

bool bstEmpty(BST_TREE* tree)
{

}

int bstCount(BST_TREE* tree)
{

}