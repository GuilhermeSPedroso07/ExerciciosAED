#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int c, *vals = ( int * ) malloc ( sizeof ( int ) * 10000 );
    
    struct ListNode *p1 = head, *p2 = head->next;
    for ( c = 0; p1 != NULL; c++ ) {
        vals[c] = 0;
        while ( p2 != NULL ) {
            if ( p2->val > p1->val ) {
                vals[c] = p2->val;
                break;
            } 
            p2 = p2->next;
        }
        p1 = p1->next;
        if ( p1 != NULL)
        p2 = p1->next;
    }
    vals = ( int * ) realloc (vals, sizeof ( int ) * c );
    *returnSize = c;
    return vals;
}

struct ListNode* createNode(int val) {
    struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* buildList(int *arr, int n) {
    if (n == 0) return NULL;
    struct ListNode *head = createNode(arr[0]);
    struct ListNode *curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void freeList(struct ListNode *head) {
    while (head) {
        struct ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    int n;
    printf("Quantidade de elementos da lista: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Valor inválido.\n");
        return 1;
    }

    int *arr = (int*) malloc(sizeof(int) * n);
    printf("Digite os %d valores: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct ListNode *head = buildList(arr, n);
    free(arr);

    int returnSize = 0;
    int *result = nextLargerNodes(head, &returnSize);

    printf("Resultado: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    freeList(head);

    return 0;
}