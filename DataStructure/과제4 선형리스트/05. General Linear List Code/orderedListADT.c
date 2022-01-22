#include "orderedListADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
