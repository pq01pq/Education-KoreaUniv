#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orderedListADT.h"

void printHeader(const char* title);

STUDENT csDummy[] = 
{
	{320001, "yangbong", "beebee@korea.ac.kr" },
	{320002, "hyoyong", "utility@korea.ac.kr" },
	{320003, "daegi", "waiting@korea.ac.kr" },
	{320004, "yondon", "ydchung@korea.ac.kr" },
	{320005, "minsoo", "msdb@korea.ac.kr" }
};

int main()
{
	int dummySize = sizeof(csDummy) / sizeof(STUDENT); // 학생 수
	LIST *csStudents = createList(cmpStudentId); //cmpStudentId 함수의 주소를 인자로 전달

	// 리스트에 데이터 삽입 : 성공
	printHeader("Insert dummy data");
	for (int i = 0; i < dummySize; i++)
	{
		STUDENT* student = (STUDENT*)malloc(sizeof(STUDENT));
		
		// csDummy 구조체에서 student 구조체로 복사
		student->id = csDummy[i].id;
		strcpy(student->name, csDummy[i].name);
		strcpy(student->email, csDummy[i].email);

		// student 구조체를 csStudents 리스트로 복사
		if (!insertNode(csStudents, (void*)student)) // pos는 계속 head에 맞춰줌
		{
			printf("Insertion failed\n");
		}
	}
	
	// Iterate elements : 성공
	printHeader("Iterate elements");
	STUDENT* curStudent;
	while (iterate(csStudents, (void**)&curStudent))	// &curStudent는 curStudent주소가 저장된 주소
	{													// iterate 함수는 curStudent의 주소값을 받아옴
		printStudent(curStudent);						// STUDENT형인 *curStudent의 주소를 void* 형으로 넘겨줌
	}													// 바꾸고자 하는 값은 curStudent 주소값
	initIterator(csStudents); // pos를 다시 head에 맞춰줌

	
	// Search elements : 성공
	printHeader("Search elements");
	int searchKeyOrder[] = { 320001, 320003, 120001 };
	for (int i = 0; i < sizeof(searchKeyOrder) / sizeof(int); i++)
	{
		int key = searchKeyOrder[i];
		STUDENT* pStudent;

		if (retrieve(csStudents, (void*)&key, (void**)&pStudent))
		{
			printf("Student found (key: %d)\n", key);
			printStudent(pStudent);
		} else
			printf("Search failed (key: %d)\n", key);
	}

	// Remove elements : 성공
	printHeader("Remove elements");
	int eraseKeyOrder[5] = { 320001, 320005, 320003, 320004, 320002 };
	for (int i = 0; i < sizeof(eraseKeyOrder) / sizeof(int); i++)
	{
		int key = eraseKeyOrder[i];

		if (removeNode(csStudents, (void*)&key))
		{
			printf("Erase successed (key: %d)\n", key);
		}
		else
		{
			printf("Erase failed (key: %d)\n", key);
		}

		printList(csStudents, printStudent);	// printList 함수로 전달되는 인자 : csStudents 리스트의 주소, printStudent 함수의 주소
	}

#if DEBUG
	// List empty check : 성공
	printHeader("List empty check");
	if (isEmpty(csStudents))
		printf("Empty\n");
	else 
		printf("Not empty\n");
#endif

	// Destory list : 성공
	csStudents = destroyList(csStudents);

#if DEBUG
	// List destroyed check : 만들어봄..
	printHeader("List destroyed check");
	if (csStudents == NULL)
		printf("Destroyed\n");
	else
		printf("Not destroyed\n");
#endif

	return 0;
}

void printHeader(const char* title)
{
	printf("\n####################\n");
	printf("# %s\n", title);

	return;
}