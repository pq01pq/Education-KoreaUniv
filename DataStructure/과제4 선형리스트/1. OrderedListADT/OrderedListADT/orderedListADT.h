#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_MAX 32

// �л� �� ����ü
typedef struct
{
	int id;
	char name[STR_MAX];
	char email[STR_MAX];
} STUDENT;

// node
typedef struct node
{
	void* pData;
	struct node* next;
} NODE;

// head ���
typedef struct
{
	NODE* head;
	NODE* rear;
	NODE* pos;
	int size;
	int(*compare) (void* pArg1, void* pArg2);
} LIST;

LIST* createList(int(*compare)(void* pArg1, void* pArg2));
LIST* destroyList(LIST* pList);
bool insertNode(LIST* pList, void* pDataIn);
bool removeNode(LIST* pList, void* pKey);
bool retrieve(LIST* pList, void* pKey, void** pDataOut);
int size(LIST* pList);
bool isEmpty(LIST* pList);
bool iterate(LIST* pList, void** pDataOut);
void initIterator(LIST* pList);
void printList(LIST* pList, void(*print)(void* pArg));

void printStudent(void* pArg);
int cmpStudentId(void* pStudent1, void* pStudent2);

static bool _insert(LIST* pList, NODE* pPre, void* pDataIn);
static void _delete(LIST* pList, NODE* pPre, NODE* pCur);
static bool _search(LIST* pList, NODE** pPre, NODE** pCur, void* pKey);

LIST* createList(int(*compare)(void* pArg1, void* pArg2)) // ���Լ��� �ּҸ� ����
{
	LIST *pList = (LIST *)malloc(sizeof(LIST));
	if (pList == NULL)
		return NULL;

	pList->head = NULL;
	pList->rear = NULL;
	pList->pos = NULL;
	pList->size = 0;
	pList->compare = compare; // compare �Լ��� �ּҸ� ����ü ������ pList->compare �Լ��� �ּҷ� ����

	return pList;
}

LIST* destroyList(LIST* pList)
{
	NODE *pDel = pList->head;

	while (pList->head != NULL)
	{
		pDel = pList->head;
		pList->head = pDel->next;
		free(pDel);
	}
	
	free(pList);

	return NULL;
}

bool insertNode(LIST* pList, void* pDataIn) // pDataIn�� STUDENT�� ����ü�� ����
{
	NODE *pPre, *pCur;
	// �ּҰ��� ������ ��
	pPre = NULL;
	pCur = NULL;
	STUDENT *pStudent = (STUDENT *)pDataIn;

	int found = _search(pList, &pPre, &pCur, &pStudent->id);

	if (!found) // �̹� ���� �����ϸ� �������� ����
	{
		int inserted = _insert(pList, pPre, pDataIn);
		if (inserted)
			return true;
		else
			return false;
	}
	else {
		printf("The value already exists.\n");
		return false;
	}
}

bool removeNode(LIST* pList, void* pKey) // pKey�� ������ id���� �ּ�
{
	if (pList->head == NULL) {
		printf("The list is empty.\n");
		return false;
	}

	NODE *pPre, *pCur;
	// �ּҰ��� ������ ��
	pPre = NULL;
	pCur = NULL;

	int found = _search(pList, &pPre, &pCur, pKey);

	if (found) {
		_delete(pList, pPre, pCur);
		return true;
	}
	else {
		printf("The value has not found.\n");
		return false;
	}
}

bool retrieve(LIST* pList, void* pKey, void** pDataOut)
{
	NODE* pPre;
	NODE* pCur;

	if (_search(pList, &pPre, &pCur, pKey))
	{
		*pDataOut = pCur->pData;
		return true;
	}
	else
	{
		*pDataOut = NULL;
		return false;
	}
}

int size(LIST* pList)
{
	return pList->size;
}

bool isEmpty(LIST* pList)
{
	if (pList->head == NULL)
		return true;
	else return false;
}

bool iterate(LIST* pList, void** pDataOut)	// void** pDataOut == void* *pDataOut
{											// *pDataOut�� �ּҰ�, pDataOut�� �ּҰ��� ����ִ� �ּ�
	if (pList->pos != NULL)					// *pDataOut�� STUDENT�� ����ü�� �ּ�
	{										// *pDataOut == curStudent, pDataOut == &curStudent
		*pDataOut = pList->pos->pData;		// *pDataOut(�ּҰ�)�� ������
		pList->pos = pList->pos->next;
		return true;
	}
	else
		return false;
}

void initIterator(LIST* pList)
{
	pList->pos = pList->head;

	return;
}

void printList(LIST* pList, void(*print)(void* pArg)) // print �Լ��� �ּҴ� printStudent �Լ��� �ּҿ� ����
{
	pList->pos = pList->head;
	while (pList->pos != NULL)
	{
		print(pList->pos->pData); // print �Լ��� ���ڷ� pList->pos->pData�� ����ü ���� == printStudent �Լ��� ����ü ���� ����
		pList->pos = pList->pos->next;
	}
	pList->pos = pList->head;
	printf("====================\n");

	return;
}

void printStudent(void* pArg) // pArg�� STUDENT�� ����ü�� �ּ�
{
	STUDENT *studentInfo;
	studentInfo = (STUDENT *)pArg;

	printf("STUDENT ID : %d\n", studentInfo->id);
	printf("NAME : %s\n", studentInfo->name);
	printf("EMAIL : %s\n", studentInfo->email);
	printf("--------------------\n");

	return;
}

// ���Լ�
int cmpStudentId(void* pStudent1, void* pStudent2) // pStudent1�� int�� key�� �ּ�, pStudent2�� STUDENT�� ����ü�� �ּ�
{
	int arg1 = *(int *)pStudent1; // �ּ��� ������ �����ؾ��ϹǷ� *(int *)�� ĳ����
	STUDENT *arg2 = (STUDENT *)pStudent2; // �ּҷ� �����ؾ��ϹǷ� (STUDENT *)�� ĳ����

	return arg1 - arg2->id;
}

////////// �����Լ� //////////

static bool _insert(LIST* pList, NODE* pPre, void* pDataIn)
{
	NODE *pNewNode = (NODE *)malloc(sizeof(NODE));
	if (pNewNode == NULL) // �޸� �Ҵ� �����ϸ�
		return false;

	pNewNode->pData = pDataIn;
	
	if (pPre == NULL) // head �տ� �����ϰų� ����Ʈ�� ����ִ� ���
	{
		pNewNode->next = pList->head;
		pList->head = pNewNode;
		pList->pos = pList->head; // pos�� head�� ����ٴ�
		if (pList->size == 0) // ����Ʈ�� ����ִ� ���
			pList->rear = pList->head; // rear == head
	}
	else {
		pNewNode->next = pPre->next;
		pPre->next = pNewNode;
		if (pNewNode->next == NULL) // rear �ڿ� ������ ���
			pList->rear = pNewNode;
	}

	pList->size++;

	return true;
}

static void _delete(LIST* pList, NODE* pPre, NODE* pCur)
{
	if (pPre == NULL) // head�� ������ ���
	{
		pList->head = pCur->next;
		pList->pos = pList->head; // pos�� head�� ����ٴ�
		if (pList->size == 1) // ������ ��尡 ������ ���� ����� ��� (head == rear �� ���)
			pList->rear = NULL;
	}
	else {
		pPre->next = pCur->next;
		if (pCur->next == NULL) // rear�� ������ ���
			pList->rear = pPre;
	}
	
	free(pCur);

	pList->size--;

	return;
}

//static bool _search(LIST* pList, NODE** pPre, NODE** pCur, void* pKey) ���������� �Ʊ���� �ּ�ó��
//{
//	*pCur = pList->head;
//	bool exceed = false;
//	while (pCur != NULL && !exceed)
//	{
//		if ((*pCur)->pData == pKey)
//			return true;
//
//		if ((*pCur)->pData > pKey)
//			exceed = true;
//		else {
//			*pPre = *pCur;
//			*pCur = (*pCur)->next;
//		}
//	}
//
//	return false;
//}

static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pKey)
{
#define COMPARE ( (*pList->compare)( pKey, (*pLoc)->pData ) ) // ���� pLoc�� ������ ũ�� ���, ������ ����, ������ 0
#define COMPARE_LAST ( (*pList->compare)( pKey, pList->rear->pData ) ) // �� ���� ������ ũ�� ���, ������ ����, ������ 0

	int result;
	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->size == 0) // ����Ʈ�� ����ִ� ���
		return false;

	if (COMPARE_LAST > 0) // pKey�� �ǵ��� ������ ū ���
	{
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	} // pKey�� �ǵ��� ������ ũ�� ���⼭ search ��

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