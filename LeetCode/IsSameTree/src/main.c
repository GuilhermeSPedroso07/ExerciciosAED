#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if ( p == NULL && q == NULL ) {
        return true;
    }
    if ( p == NULL || q== NULL ) {
        return false;
    }

    if ( p->val != q->val ) {
        return false;
    }


    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode *newNode( int value ) {
    struct TreeNode *node = ( struct TreeNode * ) malloc ( sizeof ( struct TreeNode ) );

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}


int main(int argc, char const *argv[]) {
    struct TreeNode* t1 = newNode(1);
    t1->left = newNode(2);
    t1->right = newNode(3);

    struct TreeNode* t2 = newNode(1);
    t2->left = newNode(2);
    t2->right = newNode(3);

    if (isSameTree(t1, t2)) {
        printf("Arvores iguais\n");
    } else {
        printf("Arvores diferentes\n");
    }

    t2->right->val = 4;

    if (isSameTree(t1, t2)) {
        printf("Arvores iguais\n");
    } else {
        printf("Arvores diferentes\n");
    }

    return 0;
}
