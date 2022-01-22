#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "expressionTreeADT.h"

NODE* createTree(NODE* left, const char* dataPtr, NODE* right)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	strcpy(node->data, dataPtr);
	node->left = left;
	node->right = right;

	return node;
}

void destroyTree(NODE *node)
{
	if (node != NULL)
	{
		destroyTree(node->left);
		destroyTree(node->right);
	}
	free(node);
}

char* treeData(NODE* node)
{
	return node->data;
}

bool hasChild(NODE* node)
{
	if (node != NULL || node->left != NULL || node->right != NULL)
	{
		return true;
	}

	return false;
}

double evaluate(NODE* node)
{
	if (!node)
	{
		return 0;
	}

	if (!node->left && !node->right)
	{
		return atof(node->data);
	}

	switch (node->data[0])
	{
	case '-':
		return evaluate(node->left) - evaluate(node->right);
	case '+':
		return evaluate(node->left) + evaluate(node->right);
	case '*':
		return evaluate(node->left) * evaluate(node->right);
	case '/':
		double right = evaluate(node->right);
		if (right)
		{
			return evaluate(node->left) / right;
		}
	}
	// Error
	return 0;
}

