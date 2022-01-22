#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarySearchTreeADT.h"

#define MINE 1

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
	TREE_NODE* newPtr = (TREE_NODE*)malloc(sizeof(TREE_NODE));
	newPtr->left = NULL;
	newPtr->right = NULL;
	newPtr->data = data;

	if (tree->root == NULL || tree->count == 0)
	{
		tree->root = newPtr;
		tree->count = 1;
		return true;
	}

	tree->root = _bstInsert(tree, tree->root, newPtr);
	(tree->count)++;
	return true;
}

TREE_NODE* _bstInsert(BST_TREE* tree, TREE_NODE* root, TREE_NODE* newPtr)
{
	if (!root)
		return newPtr;

	if (newPtr->data < root->data)
	{
		root->left = _bstInsert(tree, root->left, newPtr);
		return root;
	}
	else
	{
		root->right = _bstInsert(tree, root->right, newPtr);
		return root;
	}
}

void bstDelete(BST_TREE* tree, int key)
{
	tree->root = _bstDelete(tree->root, key);
}
#if MINE
TREE_NODE* _bstDelete(TREE_NODE* root, int key)
{
	if (root)
	{
		if (root->data > key)
		{
			root->left = _bstDelete(root->left, key);
		}
		else if (root->data < key)
		{
			root->right = _bstDelete(root->right, key);
		}
		else
		{
			TREE_NODE *pDel = root;
			if (!pDel->left)
			{
				root = pDel->right;
				free(pDel);
			}
			else if (!pDel->right)
			{
				root = pDel->left;
				free(pDel);
			}
			else
			{
				TREE_NODE *pReplace = root->left;
				while (pReplace->right)
				{
					pReplace = pReplace->right;
				}
				root->data = pReplace->data;
				root->left = _bstDelete(root->left, pReplace->data);
			}
		}
	}

	return root;
}
#else
TREE_NODE* _bstDelete(TREE_NODE* root, int key)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (key < root->data)
	{
		root->left = _bstDelete(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = _bstDelete(root->right, key);
	}
	else if (key == root->data)
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			TREE_NODE* newRoot = root->left;
			free(root);
			return newRoot;
		}
		else if (root->left == NULL && root->right != NULL)
		{
			TREE_NODE* newRoot = root->right;
			free(root);
			return newRoot;
		}
		else
		{
			TREE_NODE* exchPtr = findLargetNode(root->left);

			root->data = exchPtr->data;
			root->left = _bstDelete(root->left, exchPtr->data);
		}
	}

	return root;
}
#endif
TREE_NODE* findLargetNode(TREE_NODE* root)
{
	if (root == NULL)
		return NULL;

	if (root->right)
	{
		return findLargetNode(root->right);
	}

	return root;
}

TREE_NODE* bstSearch(BST_TREE* tree, int key)
{
	if (tree == NULL)
		return NULL;
	return _bstSearch(tree->root, key);
}

TREE_NODE* _bstSearch(TREE_NODE* root, int key)
{
	if (root == NULL)
		return NULL;
	if (key < root->data)
	{
		return _bstSearch(root->left, key);
	}
	else if (key > root->data)
	{
		return _bstSearch(root->right, key);
	}
	else
	{
		return root;
	}
}

void bstTraverse(BST_TREE* tree, void(*process)(TREE_NODE* root))
{
	_bstTraverse(tree->root, process);
	printf("\n");
}

void _bstTraverse(TREE_NODE* root, void(*process)(TREE_NODE* root))
{
	if (root)
	{
		_bstTraverse(root->left, process);
		process(root);
		_bstTraverse(root->right, process);
	}
}

void bstPrintData(TREE_NODE* root)
{
	if (root)
	{
		printf("%d\t", root->data);
	}
}

bool bstEmpty(BST_TREE* tree)
{
	return tree->count == 0;
}

int bstCount(BST_TREE* tree)
{
	return tree->count;
}