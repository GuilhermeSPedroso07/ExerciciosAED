#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct brackets {
    char brackets;

    struct brackets *next;
} stack;

void pilha( char c , stack **cabeca) {
    stack *new = ( stack * ) malloc ( sizeof ( stack ) );

    new->brackets = c;
    new->next = (*cabeca)->next;
    (*cabeca)->next = new;
}

void freeAll(stack **cabeca) {
    stack *temp = (*cabeca)->next;
    
    while ( temp != NULL ) {
        (*cabeca)->next = temp->next;
        free(temp);
        temp = (*cabeca)->next;
    }
    free ( (*cabeca) );
}

bool isValid(char* s) {
    stack *cabeca = ( stack * ) malloc ( sizeof ( stack ) );
    cabeca->next = NULL;
    char *atual = s;
    stack *temp;

    while ( *atual != '\0' ) {
        if ( *atual == '(' || *atual == '[' || *atual == '{' ) {
            pilha(*atual, &cabeca);
        } else if ( *atual == ')' ) {
            if ( cabeca->next == NULL || (cabeca->next)->brackets != '(' ) {
                freeAll(&cabeca);
                return false;
            } else {
                temp = cabeca->next;
                cabeca->next = (cabeca->next)->next;
                free ( temp );
            }
        } else if ( *atual == '}' ) {
            if ( cabeca->next == NULL || (cabeca->next)->brackets != '{' ) {
                freeAll(&cabeca);
                return false;
            } else {
                temp = cabeca->next;
                cabeca->next = (cabeca->next)->next;
                free ( temp );
            }
        } else if ( cabeca->next == NULL || (cabeca->next)->brackets != '[' ) {
            freeAll(&cabeca);
                return false;
            } else {
                temp = cabeca->next;
                cabeca->next = (cabeca->next)->next;
                free ( temp );
                }
    atual++;
    }
    if ( cabeca->next == NULL ) {
        freeAll(&cabeca);
        return true;
    }
    freeAll(&cabeca);
    return false;
}

int main(int argc, char const *argv[]) {
    printf("Hello World!\n");

    return 0;
}
