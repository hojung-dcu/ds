#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"

// 공백 원형 연결 리스트 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

// 원형 연결 리스트 출력
void printList(linkedList_h* L) {
	listNode* p;
	printf(" CL = (");
	if (L->head == NULL) {
		printf(")\n");
		return;
	}
	p = L->head;
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != L->head) printf(", ");
	} while (p != L->head);
	printf(") \n");
}

// 첫 번째 노드 삽입
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = newNode;  // 자기 자신을 가리킴
	}
	else {
		temp = L->head;
		while (temp->link != L->head) {
			temp = temp->link;
		}
		newNode->link = L->head;
		temp->link = newNode;
		L->head = newNode;
	}
}

// 노드 검색
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	if (L->head == NULL) return NULL;

	temp = L->head;
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		temp = temp->link;
	} while (temp != L->head);

	return NULL;
}

// 중간 노드 삽입
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 노드 삭제
void deleteNode(linkedList_h* L, listNode* old) {
	listNode* pre;
	if (L->head == NULL) return;

	if (L->head->link == L->head) {  // 노드가 하나만 있는 경우
		free(L->head);
		L->head = NULL;
		return;
	}

	pre = L->head;
	while (pre->link != old) {
		pre = pre->link;
	}
	pre->link = old->link;

	if (old == L->head) {  // 삭제할 노드가 head인 경우
		L->head = old->link;
	}
	free(old);
}