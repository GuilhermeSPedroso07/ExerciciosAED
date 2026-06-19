#include <stdio.h>
#include <stdlib.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 

void remover ( struct TreeNode* root, struct TreeNode* parent, char dir, struct TreeNode** raiz ) {
    struct TreeNode* p = root;
    struct TreeNode* n = root;
    if ( root->left != NULL ) {
        p = p->left;
        if ( p->right == NULL ) {
            root->val = p->val;
            n->left = p->left;
        } else {
            while ( p->right != NULL ) {
                n = p;
                p = p->right;
            }
            root->val = p->val;
            n->right = p->left;
        }
    } else if ( root->right != NULL ) {
        p = p->right;
        if ( p->left == NULL ) {
            root->val = p->val;
            n->right = p->right;
        } else {
            while ( p->left != NULL ) {
                n = p;
                p = p->left;
            }
            root->val = p->val;
            n->left = p->right;
        }
    } else if ( dir == 'n' ) {
        (*raiz) = NULL;
    } else {
        if ( dir == 'l' ) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode *p = root;
    struct TreeNode *n = root;
    char dir = 'n';
    
    while ( p != NULL ) {
        if ( p->val == key ) {
            remover ( p, n, dir, &root );
            break;
        } else {
            if ( p->val < key ) {
                n = p;
                p = p->right;
                dir = 'r';
            } else {
                n = p;
                p = p->left;
                dir = 'l';
            }
        }
    }

return root;
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
