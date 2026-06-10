#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;

    struct ListNode *next;
};

void insert ( struct ListNode **head, int value ) {
    struct ListNode *pre, *next;
    pre = *head;
    next = *head;
    while ( next != NULL ) {
        if ( next->val > value ) {
            break;
        }
        pre = next;
        next = next->next;
    }
    struct ListNode *new = ( struct ListNode * ) malloc ( sizeof ( struct ListNode ) );
    new->next = next;
    new->val = value;
    if ( next != *head ) {
        pre->next = new;
    } else {
        *head = new;
    }
}

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *output = ( struct ListNode * ) malloc ( sizeof ( struct ListNode ) );
    output->next = NULL;
    output->val = head->val;
    struct ListNode *p = head->next;

    while ( p != NULL ) {
        insert ( &output, p->val );
        p = p->next;
    }
    return output;
}

int main(int argc, char const *argv[])
{
    srand ( time ( NULL ) );
    struct ListNode *head = ( struct ListNode * ) malloc ( sizeof ( struct ListNode ) );
    struct ListNode *p = head;
    struct ListNode *tmp;
    head->next = NULL;
    head->val = rand ( ) % 20;

    int size = rand ( ) % 15 + 1;

    for ( int i = 0; i < size - 1; i++ ) {
        struct ListNode *new = ( struct ListNode * ) malloc ( sizeof ( struct ListNode ) );
        new->next = head->next;
        new->val = rand ( ) % 20;
        head->next = new;
    }

    while ( p != NULL ) {
        printf ( "%d ", p->val );
        p = p->next;
    }
    printf ( "\n" );

    struct ListNode *sorted = insertionSortList ( head );

    p = sorted;
    while ( p != NULL ) {
        printf ( "%d ", p->val );
        p = p->next;
    }

    p = head;

    while ( p != NULL ) {
        tmp = p;
        p = p->next;
        free ( tmp );
    }

    p = sorted;

    while ( p != NULL ) {
        tmp = p;
        p = p->next;
        free ( tmp );
    }
    
    return 0;
}
