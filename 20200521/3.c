#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct treeNode {
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
};

struct linkNode {
    struct treeNode *data;
    struct linkNode *next;
};

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

typedef struct linkNode LinkNode;

void insertNode(TreeNodePtr *treePtr, int value);

void pop(LinkNode *node);

void push(LinkNode *node, TreeNodePtr);

void levelOrder(TreeNodePtr nodePtr);

int main(void) {
    TreeNodePtr rootPtr = NULL; // tree initially empty

    insertNode(&rootPtr, 12);
    insertNode(&rootPtr, 15);
    insertNode(&rootPtr, 8);
    insertNode(&rootPtr, 6);
    insertNode(&rootPtr, 17);
    insertNode(&rootPtr, 19);
    insertNode(&rootPtr, 2);
    insertNode(&rootPtr, 4);

    levelOrder(rootPtr);


    return 0;
}

void insertNode(TreeNodePtr *treePtr, int value) {
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%d not inserted. No memory available.\n", value);
        }
    } else {
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        } else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        } else { // duplicate data value ignored
            printf("%s", "dup");
        }
    }
}

void levelOrder(TreeNodePtr nodePtr) {
    LinkNode *linkNode = (LinkNode *) malloc(sizeof(LinkNode));
    linkNode->next = malloc(sizeof(LinkNode));
    linkNode->next->data = nodePtr;
    LinkNode *temp = linkNode->next;

    while (temp->data->rightPtr != NULL || temp->data->leftPtr != NULL) {
        if (temp->data->leftPtr != NULL) {
            push(linkNode, temp->data->leftPtr);
        }
        if (temp->data->rightPtr != NULL) {
            push(linkNode, temp->data->rightPtr);
        }
        temp = temp->next;
    }
    while (linkNode->next != NULL) {
        pop(linkNode);
    }
}

void pop(LinkNode *node) {
    if (node != NULL) printf("%d ", node->next->data->data);
    node->next = node->next->next;
}

void push(LinkNode *node, TreeNodePtr newData) {
    while (node->next != NULL)
        node = node->next;
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = newData;
    newNode->next = NULL;
    node->next = newNode;
}
