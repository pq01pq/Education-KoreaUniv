#include "orderedListADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

LIST* createList(int(*compare)(void* pArg1, void* pArg2))
{
	LIST* list;

	list = (LIST*)malloc(sizeof(LIST));
	if (list)
	{
		list->head = NULL;
		list->pos = NULL;
		list->rear = NULL;
		list->size = 0;
		list->compare = compare;
	}

	return list;
}

LIST* destoryList(LIST* pList)
{
	NODE* pCur;

	if (pList)
	{
		while (pList->size > 0)
		{
			free(pList->head->pData);

			pCur = pList->head;
			pList->head = pList->head->next;
			pList->size--;
			free(pCur);
		}

		free(pList);
	}

	return NULL;
}

bool insert(LIST* pList, void* pDataIn)
{
	NODE* pPre;
	NODE* pCur;

	if (_search(pList, &pPre, &pCur, pDataIn))
		return false;	// Key duplicated

	return _insert(pList, pPre, pDataIn);
}

static bool _insert(LIST* pList, NODE* pPre, void* pDataIn)
{
	NODE* pNew;

	if (!(pNew = (NODE*)malloc(sizeof(NODE))))
		return false;

	pNew->pData = pDataIn;
	pNew->next = NULL;

	if (pPre == NULL)
	{
		if (pList->head == NULL)
			pList->rear = pNew;

		pNew->next = pList->head;
		pList->head = pNew;
	} else
	{
		pNew->next = pPre->next;
		pPre->next = pNew;

		if (pNew->next == NULL)
			pList->rear = pNew;
	}

	(pList->size)++;
	return true;
}

bool removeList(LIST* pList, void* pKey)
{
	NODE* pPre;
	NODE* pCur;

	if (_search(pList, &pPre, &pCur, pKey))
	{
		_delete(pList, pPre, pCur);
		return true;
	}

	return false;
}

static void _delete(LIST* pList, NODE* pPre, NODE* pCur)
{
	if (pPre == NULL)
		pList->head = pCur->next;
	else
		pPre->next = pCur->next;

	if (pCur->next == NULL)
		pList->rear = pPre;

	(pList->size)--;

	free(pCur->pData);
	free(pCur);
}

bool iterate(LIST* pList, void** pDataOut)
{
	if (pList->size == 0)
		return false;

	if (pList->pos == NULL)
	{
		pList->pos = pList->head;
		*pDataOut = pList->pos->pData;
		return true;
	}
	
	if (pList->pos->next == NULL)
		return false;

	pList->pos = pList->pos->next;
	*pDataOut = pList->pos->pData;
	return true;
}

int size(LIST* pList)
{
	return pList->size;
}

bool isEmpty(LIST* pList)
{
	if (pList->size)
		return false;
	return true;
}

void initIterator(LIST* pList)
{
	pList->pos = NULL;
}

void printList(LIST* pList, void(*print)(void* pArg))
{
	void* pData;
	initIterator(pList);

	while (iterate(pList, &pData))
	{
		print(pData);
	}
	printf("====================\n");
}

void printStudent(void* pArg)
{
	STUDENT* pStudent = (STUDENT*)pArg;
	if (pStudent != NULL)
	{
		printf("STUDENT ID: %d\nNAME: %s\nEMAIL: %s\n", pStudent->id, pStudent->name, pStudent->email);
		printf("--------------------\n");
	}
}

int cmpStudentId(void* pStudent1, void* pStudent2)
{
	int id1, id2;
	id1 = ((STUDENT*)pStudent1)->id;
	id2 = ((STUDENT*)pStudent2)->id;

	if (id1 < id2)
		return -1;
	else if (id1 > id2)
		return 1;
	else
		return 0;
}

bool retrieve(LIST* pList, void* pKey, void** pDataOut)
{
	NODE* pPre;
	NODE* pCur;

	if (_search(pList, &pPre, &pCur, pKey))
	{
		*pDataOut = pCur->pData;
		return true;
	} else
	{
		*pDataOut = NULL;
		return false;
	}
}

static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pKey)
{
#define COMPARE (((*pList->compare)(pKey, (*pLoc)->pData)))
#define COMPARE_LAST ((*pList->compare) (pKey, pList->rear->pData))

	int result;
	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->size == 0)
		return false;

	if (COMPARE_LAST > 0)
	{
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	}

	while ((result = COMPARE) > 0)
	{
		*pPre = *pLoc;
		*pLoc = (*pLoc)->next;
	}

	if (result == 0)
		return true;
	else
		return false;
}