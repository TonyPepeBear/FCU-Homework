#include <stdio.h>

typedef struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
} node;

void res(node *root, int level, int *counter) {
    if (root == NULL) { return; }
    if (*counter < level) {
        printf("%d ", root->val);
        *counter += 1;
    }
    res(root->right, level + 1, counter);
    res(root->left, level + 1, counter);
}

void rightSideView(node *root) {
    int counter = 0;
    res(root, 1, &counter);
}
