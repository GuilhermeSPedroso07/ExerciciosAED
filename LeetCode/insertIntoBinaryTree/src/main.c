#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;

    struct TreeNode *left;
    struct TreeNode *right;
};


void insert ( struct TreeNode **root, int value ) {
    struct TreeNode *new = ( struct TreeNode * ) malloc ( sizeof ( struct TreeNode ) );
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    (*root) = new;
}

void insertion ( struct TreeNode *root, int value ) {
    if ( value < root->val ) {
        if ( root->left != NULL ) {
            insertion ( root->left, value );
        } else {
            insert ( &(root->left), value );
        }
    } else {
        if ( root->right != NULL ) {
            insertion ( root->right, value );
        } else {
            insert ( &(root->right), value );
        }
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if ( root != NULL ) {
        insertion ( root, val );
    } else {
        insert ( &(root), val );
    }

    return root;
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
