#include <stdio.h>
#include <stdlib.h>

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