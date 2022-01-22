#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STR_MAX 16

typedef struct node
{
	char dataPtr[STR_MAX];
	struct node* left;
	struct node* right;
} NODE;

NODE* createTree(NODE* left, const char* dataPtr, NODE* right)
{
	NODE *pNewNode = (NODE *)malloc(sizeof(NODE));
	if (pNewNode == NULL)
	{
		printf("Tree has not been created.\n");
		return NULL;
	}

	pNewNode->left = left;
	pNewNode->right = right;
	strcpy(pNewNode->dataPtr, dataPtr);

	return pNewNode;
}

NODE* destroyTree(NODE* node)
{
	if (node != NULL)
	{
		node->left = destroyTree(node->left); // node->left == NULL 이 됨
		node->right = destroyTree(node->right); // node->right == NULL 이 됨

		free(node);
		node = NULL;
	}

	return node;
}

void treeData(NODE* node, char formula[])
{
	if (node)
	{
		if (node->dataPtr[0] == '+' || node->dataPtr[0] == '-' || node->dataPtr[0] == '*' || node->dataPtr[0] == '/')
		{
			if(node->left || node->right)
				strcat(formula, "(");

			treeData(node->left, formula);

			strcat(formula, node->dataPtr);

			treeData(node->right, formula);

			if (node->left || node->right)
				strcat(formula, ")");
		}
		else
		{
			strcat(formula, node->dataPtr);
		}
	}

	return;
}

bool hasChild(NODE* node)
{
	if (node->left == NULL && node->right == NULL)
		return false;
	else
		return true;
}

double evaluate(NODE* node)
{
	double temp;

	if (node->left == NULL)
	{
		if (node->right == NULL) // 현재 노드가 말단 노드일 경우
			temp = (double)atoi(node->dataPtr);
		else // 단항연산자일 경우
		{
			switch (*node->dataPtr) {
			case '+':
				temp = (double)atoi(node->dataPtr);
				break;
			case '-':
				temp = (double)-atoi(node->dataPtr);
				break;
			default :
				printf("Invalid formula (unary form at binary operator)\n");
				temp = (double)INT_MAX;
				break;
			}
		}

		return temp;
	}

	double leftEvaluate = evaluate(node->left);
	if ((int)leftEvaluate == INT_MAX)
		return (double)INT_MAX;

	double rightEvaluate = evaluate(node->right);
	if ((int)rightEvaluate == INT_MAX)
		return (double)INT_MAX;

	switch (*node->dataPtr)
	{
	case '+' :
		temp = leftEvaluate + rightEvaluate;
		break;
	case '-' :
		temp = leftEvaluate - rightEvaluate;
		break;
	case '*':
		temp = leftEvaluate * rightEvaluate;
		break;
	case '/':
		temp = leftEvaluate / rightEvaluate;
		break;
	default :
		printf("Invalid formula (not an operator)\n");
		temp = (double)INT_MAX;
		break;
	}
	
	return temp;
}