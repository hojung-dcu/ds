#pragma once
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
    element key;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

void displayInorder(treeNode* root);
