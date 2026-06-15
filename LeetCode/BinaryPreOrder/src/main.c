#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;

    struct TreeNode *left;
    struct TreeNode *right;
};

void preOrder ( struct TreeNode* root, int *output, int *amount ) {
    if ( root == NULL ) {
        return;
    }

    output[*amount] = root->val;
    ( *amount )++;
    preOrder ( root->left, output, amount );
    preOrder ( root->right, output, amount );
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *output = ( int * ) malloc ( sizeof ( int ) * 100 );
    int amount = 0;
    preOrder ( root, output, &amount );
    output = realloc ( output, sizeof ( int ) * amount );
    *returnSize = amount;
    return output;
}

int main() {
    struct TreeNode *n1 = malloc ( sizeof(struct TreeNode ) );
    struct TreeNode *n2 = malloc ( sizeof(struct TreeNode ) );
    struct TreeNode *n3 = malloc ( sizeof(struct TreeNode ) );
    struct TreeNode *n4 = malloc ( sizeof(struct TreeNode ) );
    struct TreeNode *n5 = malloc ( sizeof(struct TreeNode ) );
    struct TreeNode *n6 = malloc ( sizeof(struct TreeNode ) );
    struct TreeNode *n7 = malloc ( sizeof(struct TreeNode ) );

    n1->val = 1; n1->left = NULL; n1->right = NULL;
    n2->val = 2; n2->left = n1;   n2->right = n3;
    n3->val = 3; n3->left = NULL; n3->right = NULL;
    n4->val = 4; n4->left = n2;   n4->right = n6;
    n5->val = 5; n5->left = NULL; n5->right = NULL;
    n6->val = 6; n6->left = n5;   n6->right = n7;
    n7->val = 7; n7->left = NULL; n7->right = NULL;

    int size;
    int *result = preorderTraversal ( n4, &size );

    printf ( "Percurso em pré-ordem: " );
    for ( int i = 0; i < size; i++ ) {
        printf ( "%d ", result[i] );
    }
    printf ( "\n" );

    free ( result );
    free ( n1 );
    free ( n2 );
    free ( n3 );
    free ( n4 );
    free ( n5 );
    free ( n6 );
    free ( n7 );

    return 0;
}