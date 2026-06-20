#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;

    struct TreeNode *left;
    struct TreeNode *right;
};

void findLeftLeaf ( struct TreeNode *root, int *sum ) {
    if ( root == NULL ) {
        return;
    }
    struct TreeNode *p = root->left;
    if ( p != NULL ) {
        if ( p->left == NULL && p->right == NULL ) {
            *sum += p->val;
        }
    }
    findLeftLeaf ( p, sum );
    findLeftLeaf ( root->right, sum );
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    findLeftLeaf ( root, &sum );
    return sum;
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
