#include <stdio.h>
#include <stdlib.h>
#include "LinkedPoly.h"

ListHead* createLinkedList(void) {
    ListHead* L = (ListHead*)malloc(sizeof(ListHead));
    L->head = NULL;
    return L;
}

void appendTerm(ListHead* L, float coef, int expo) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
    } else {
        ListNode* p = L->head;
        while (p->link != NULL) p = p->link;
        p->link = newNode;
    }
}

void addPoly(ListHead* A, ListHead* B, ListHead* C) {
    ListNode* pA = A->head;
    ListNode* pB = B->head;
    while (pA && pB) {
        if (pA->expo == pB->expo) {
            float sum = pA->coef + pB->coef;
            if (sum != 0) appendTerm(C, sum, pA->expo);
            pA = pA->link; pB = pB->link;
        } else if (pA->expo > pB->expo) {
            appendTerm(C, pA->coef, pA->expo);
            pA = pA->link;
        } else {
            appendTerm(C, pB->coef, pB->expo);
            pB = pB->link;
        }
    }
    for (; pA != NULL; pA = pA->link) appendTerm(C, pA->coef, pA->expo);
    for (; pB != NULL; pB = pB->link) appendTerm(C, pB->coef, pB->expo);
}

void printPoly(ListHead* L) {
    ListNode* p = L->head;
    for (; p; p = p->link) {
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL) printf(" +");
    }
    printf("\n");
}
