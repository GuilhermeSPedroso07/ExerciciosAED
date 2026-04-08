/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0, valSomado = 0;
    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *lista = ( struct ListNode * ) malloc ( sizeof ( struct ListNode ) );
    struct ListNode *ultimo = lista;;
    lista->next = NULL;
    if ( p1->val + p2->val >= 10 ) {
        carry = 1;
        lista->val = (p1->val + p2->val) % 10;
    } else {
        lista->val = p1->val + p2->val;
        carry = 0;
    }
    if ( p1->next != NULL ) {
        p1 = p1->next;
        valSomado += p1->val;
    }
    if ( p2->next != NULL ) {
        p2 = p2->next;
        valSomado += p2->val;
    }
    while ( valSomado + carry != 0 || p1->next != NULL || p2->next != NULL ) {
        struct ListNode *novo = ( struct ListNode * ) malloc ( sizeof ( struct ListNode ) );
        ultimo->next = novo;
        novo->next = NULL;
        ultimo = novo;
        if ( valSomado + carry >= 10 ) {
            novo->val = (valSomado + carry) % 10;
            carry = 1;
            valSomado = 0;
        } else {
            novo->val = valSomado + carry;
            carry = 0;
            valSomado = 0;
        }
        if ( p1->next != NULL ) {
            p1 = p1->next;
            valSomado += p1->val;
        }
        if ( p2->next != NULL ) {
            p2 = p2->next;
            valSomado += p2->val;
        }
}
return lista;
}
