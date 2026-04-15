#pragma once

// 원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;

// 함수 선언
linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
listNode* searchNode(linkedList_h* L, char* x);
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);
void deleteNode(linkedList_h* L, listNode* old);