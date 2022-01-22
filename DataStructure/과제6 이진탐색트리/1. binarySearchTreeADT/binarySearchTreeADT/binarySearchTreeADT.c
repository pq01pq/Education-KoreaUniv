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
	TREE_NODE *node = (TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (node)
	{
		node->data = data;
		node->left = node->right = NULL; // NULL �ʱ�ȭ ���ϸ� ����
		if (tree->root == NULL) // default
		{
			tree->root = node;
		}
		else
		{
			if (node->data < tree->root->data)
			{
				tree->root->left = _bstInsert(tree->root->left, node);
			}
			else // node->data >= tree->root->data
			{
				tree->root->right = _bstInsert(tree->root->right, node);
			}
		}
		tree->count++;
		return true;
	}
	else return false;
}

TREE_NODE* _bstInsert(TREE_NODE* root, TREE_NODE* node)
{
	if (root == NULL)
	{
		return node;
	}
	else
	{
		if (node->data < root->data)
		{
			root->left = _bstInsert(root->left, node);
		}
		else // data >= root->data
		{
			root->right = _bstInsert(root->right, node);
		}
	}
	return root;
}

bool bstDelete(BST_TREE* tree, int key)
{
	if (tree)
	{
		bool success = false;
		tree->root = _bstDelete(tree->root, key, &success);
		if (success)
		{
			tree->count--;
			return true;
		}
	}
	return false;
}

TREE_NODE* _bstDelete(TREE_NODE* root, int key, bool *success)
{
	if (root)
	{
		if (key < root->data)
		{
			root->left = _bstDelete(root->left, key, success);
		}
		else if (key > root->data)
		{
			root->right = _bstDelete(root->right, key, success);
		}
		else // key == root->data
		{
			TREE_NODE* del;
			if (!root->left) // ���� �ڽ��� ���� ��
			{
				del = root;
				root = del->right;
				free(del);
			}
			else if (!root->right) // ������ �ڽ��� ���� ��
			{
				del = root;
				root = del->left;
				free(del);
			}
			else // ���� �ڽİ� ������ �ڽ��� �� �� ���� ��
			{
				del = root->right; // ������ �κ�Ʈ������ ���� ���� ��带 ã��(���� �ڽ��� ����)
				while (del->left != NULL)
				{
					del = del->left;
				}
				root->data = del->data;
				root->right = _bstDelete(root->right, del->data, success);	// ������ �κ�Ʈ������ �ش� del data�� ���� ����� �����۾�
			}																// �ش� del data�� ���� ����� ���� �ڽ��� �����Ƿ� ����
			*success = true;
		}
	}
	return root;
}

TREE_NODE* bstSearch(BST_TREE* tree, int key)
{
	if (tree)
		return _bstSearch(tree->root, key);
	else return NULL;
}

TREE_NODE* _bstSearch(TREE_NODE* root, int key)
{
	if (!root)
		return root;

	if (key < root->data)
	{
		return _bstSearch(root->left, key);
	}
	else if (key > root->data)
	{
		return _bstSearch(root->right, key);
	}
	else // key == root->data
	{
		return root;
	}
}

bool bstEmpty(BST_TREE* tree)
{
	return (tree->count == 0);

}

int bstCount(BST_TREE* tree)
{
	if (tree)
		return tree->count;
	else return 0;
}