#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void sum ( struct TreeNode* root, int *acc ) {
    if ( root == NULL ) {
        return;
    }

    sum ( root->right, acc );
    root->val = root->val + *acc;
    *acc = root->val;
    sum ( root->left, acc );
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int acc = 0;
    sum ( root, &acc );
    return root;
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
