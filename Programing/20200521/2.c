#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct treeNode {
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
};

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);

TreeNode *binaryTreeSearch(TreeNodePtr treePtr, int f);

// function main begins program execution
int main(void) {
    TreeNodePtr rootPtr = NULL; // tree initially empty

    // insert random values between 0 and 14 in the tree
    insertNode(&rootPtr, 12);
    insertNode(&rootPtr, 15);
    insertNode(&rootPtr, 8);
    insertNode(&rootPtr, 6);
    insertNode(&rootPtr, 17);
    insertNode(&rootPtr, 19);
    insertNode(&rootPtr, 24);

    printf("%p\n", binaryTreeSearch(rootPtr, 12));
    printf("%p\n", binaryTreeSearch(rootPtr, 24));
    printf("%p\n", binaryTreeSearch(rootPtr, 6));
    printf("%p\n", binaryTreeSearch(rootPtr, 11));
    printf("%p\n", binaryTreeSearch(rootPtr, 1));
    printf("%p\n", binaryTreeSearch(rootPtr, 2));

    return 0;
}

TreeNode *binaryTreeSearch(TreeNodePtr treePtr, int f) {
    if (treePtr == NULL) return NULL;
    if (f < treePtr->data) {
        return binaryTreeSearch(treePtr->leftPtr, f);
    } else if (f > treePtr->data) {
        return binaryTreeSearch(treePtr->rightPtr, f);

    } else {
        return treePtr;
    }
}

// insert node into tree
void insertNode(TreeNodePtr *treePtr, int value) {
    // if tree is empty
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        // if memory was allocated, then assign data
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%d not inserted. No memory available.\n", value);
        }
    } else { // tree is not empty
        // data to insert is less than data in current node
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }
            // data to insert is greater than data in current node
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        } else { // duplicate data value ignored
            printf("%s", "dup");
        }
    }
}

