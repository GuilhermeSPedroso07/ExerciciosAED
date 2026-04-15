#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *newNode(int val);
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
void printList(struct ListNode *head);

int main() {
    struct ListNode *l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    struct ListNode *l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    printf("Lista 1: ");
    printList(l1);

    printf("Lista 2: ");
    printList(l2);

    struct ListNode *merged = mergeTwoLists(l1, l2);

    printf("Lista mesclada: ");
    printList(merged);

    return 0;
}

void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) {
        return list1;
    }
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct ListNode *cabeca = (struct ListNode *) malloc(sizeof(struct ListNode));
    cabeca->next = NULL;

    struct ListNode *lista1 = list1, *lista2 = list2, *atual = cabeca;

    while (lista1 != NULL || lista2 != NULL) {
        if (lista1 == NULL) {
            atual->next = newNode(lista2->val);
            atual = atual->next;
            lista2 = lista2->next;
        } else if (lista2 == NULL) {
            atual->next = newNode(lista1->val);
            atual = atual->next;
            lista1 = lista1->next;
        } else if (lista1->val > lista2->val) {
            atual->next = newNode(lista2->val);
            atual = atual->next;
            lista2 = lista2->next;
        } else {
            atual->next = newNode(lista1->val);
            atual = atual->next;
            lista1 = lista1->next;
        }
    }
    return cabeca->next;
}

struct ListNode *newNode(int val) {
    struct ListNode *new = (struct ListNode *) malloc(sizeof(struct ListNode));
    new->next = NULL;
    new->val = val;
    return new;
}