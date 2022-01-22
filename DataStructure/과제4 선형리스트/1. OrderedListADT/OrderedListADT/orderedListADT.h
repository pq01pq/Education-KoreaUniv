#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_MAX 32

// 학생 형 구조체
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

// head 등등
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

LIST* createList(int(*compare)(void* pArg1, void* pArg2)) // 비교함수의 주소를 지정
{
	LIST *pList = (LIST *)malloc(sizeof(LIST));
	if (pList == NULL)
		return NULL;

	pList->head = NULL;
	pList->rear = NULL;
	pList->pos = NULL;
	pList->size = 0;
	pList->compare = compare; // compare 함수의 주소를 구조체 내부의 pList->compare 함수의 주소로 배정

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

bool insertNode(LIST* pList, void* pDataIn) // pDataIn은 STUDENT형 구조체를 받음
{
	NODE *pPre, *pCur;
	// 주소값이 변수의 값
	pPre = NULL;
	pCur = NULL;
	STUDENT *pStudent = (STUDENT *)pDataIn;

	int found = _search(pList, &pPre, &pCur, &pStudent->id);

	if (!found) // 이미 값이 존재하면 삽입하지 않음
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

bool removeNode(LIST* pList, void* pKey) // pKey는 대조할 id값의 주소
{
	if (pList->head == NULL) {
		printf("The list is empty.\n");
		return false;
	}

	NODE *pPre, *pCur;
	// 주소값이 변수의 값
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
{											// *pDataOut은 주소값, pDataOut은 주소값이 들어있는 주소
	if (pList->pos != NULL)					// *pDataOut은 STUDENT형 구조체의 주소
	{										// *pDataOut == curStudent, pDataOut == &curStudent
		*pDataOut = pList->pos->pData;		// *pDataOut(주소값)을 변경함
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

void printList(LIST* pList, void(*print)(void* pArg)) // print 함수의 주소는 printStudent 함수의 주소와 같음
{
	pList->pos = pList->head;
	while (pList->pos != NULL)
	{
		print(pList->pos->pData); // print 함수의 인자로 pList->pos->pData의 구조체 전달 == printStudent 함수로 구조체 인자 전달
		pList->pos = pList->pos->next;
	}
	pList->pos = pList->head;
	printf("====================\n");

	return;
}

void printStudent(void* pArg) // pArg는 STUDENT형 구조체의 주소
{
	STUDENT *studentInfo;
	studentInfo = (STUDENT *)pArg;

	printf("STUDENT ID : %d\n", studentInfo->id);
	printf("NAME : %s\n", studentInfo->name);
	printf("EMAIL : %s\n", studentInfo->email);
	printf("--------------------\n");

	return;
}

// 비교함수
int cmpStudentId(void* pStudent1, void* pStudent2) // pStudent1은 int형 key의 주소, pStudent2는 STUDENT형 구조체의 주소
{
	int arg1 = *(int *)pStudent1; // 주소의 값으로 접근해야하므로 *(int *)로 캐스팅
	STUDENT *arg2 = (STUDENT *)pStudent2; // 주소로 접근해야하므로 (STUDENT *)로 캐스팅

	return arg1 - arg2->id;
}

////////// 내부함수 //////////

static bool _insert(LIST* pList, NODE* pPre, void* pDataIn)
{
	NODE *pNewNode = (NODE *)malloc(sizeof(NODE));
	if (pNewNode == NULL) // 메모리 할당 실패하면
		return false;

	pNewNode->pData = pDataIn;
	
	if (pPre == NULL) // head 앞에 삽입하거나 리스트가 비어있는 경우
	{
		pNewNode->next = pList->head;
		pList->head = pNewNode;
		pList->pos = pList->head; // pos는 head를 따라다님
		if (pList->size == 0) // 리스트가 비어있는 경우
			pList->rear = pList->head; // rear == head
	}
	else {
		pNewNode->next = pPre->next;
		pPre->next = pNewNode;
		if (pNewNode->next == NULL) // rear 뒤에 삽입할 경우
			pList->rear = pNewNode;
	}

	pList->size++;

	return true;
}

static void _delete(LIST* pList, NODE* pPre, NODE* pCur)
{
	if (pPre == NULL) // head를 삭제할 경우
	{
		pList->head = pCur->next;
		pList->pos = pList->head; // pos는 head를 따라다님
		if (pList->size == 1) // 삭제할 노드가 마지막 남은 노드일 경우 (head == rear 인 경우)
			pList->rear = NULL;
	}
	else {
		pPre->next = pCur->next;
		if (pCur->next == NULL) // rear를 삭제할 경우
			pList->rear = pPre;
	}
	
	free(pCur);

	pList->size--;

	return;
}

//static bool _search(LIST* pList, NODE** pPre, NODE** pCur, void* pKey) 뻘짓했지만 아까워서 주석처리
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
#define COMPARE ( (*pList->compare)( pKey, (*pLoc)->pData ) ) // 현재 pLoc의 값보다 크면 양수, 작으면 음수, 같으면 0
#define COMPARE_LAST ( (*pList->compare)( pKey, pList->rear->pData ) ) // 맨 뒤의 값보다 크면 양수, 작으면 음수, 같으면 0

	int result;
	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->size == 0) // 리스트가 비어있는 경우
		return false;

	if (COMPARE_LAST > 0) // pKey가 맨뒤의 값보다 큰 경우
	{
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	} // pKey가 맨뒤의 값보다 크면 여기서 search 끝

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