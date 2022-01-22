#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "expressionTreeADT.h"

void main(void)
{
	NODE *left, *right, *root;

	// -> 6 / 2
	left = createTree(NULL, "6", NULL);
	right = createTree(NULL, "2", NULL);
	root = createTree(left, "/", right);

	// -> 3 + ( )
	left = createTree(NULL, "3", NULL);
	right = root;
	root = createTree(left, "+", right);

	// -> ( ) / 4
	left = root;
	right = createTree(NULL, "4", NULL);
	root = createTree(left, "/", right);

	char formula[STR_MAX] = "\0"; // 초기화 안하면 오류
	treeData(root, formula);

	if (hasChild(root))
	{
		printf("Formula : %s\n", formula);
		printf("Result : %.1f\n", evaluate(root));
	}

	root = destroyTree(root);
#if DEBUG
	printf("%p\n", root);
#endif

	return;
}