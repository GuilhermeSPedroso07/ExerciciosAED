#include <stdio.h>

typedef struct list {
    int value;
    int manyTimes;

    struct list *next;
} lista;

void addToList ( int num, lista **list ) {
    lista *ptr = ( *list );
    while ( ptr->value != num ) {
        if ( ptr->next == NULL ) {
            ptr->next = ( lista * ) malloc ( sizeof ( lista ) );
            ptr->next->manyTimes = 0;
            ptr->next->value = num;
            ptr->next->next = NULL;
        }
        ptr = ptr->next;
    }
    ptr->manyTimes++;
}

int majorElement ( lista *list, int n ) {
    int maxElement = 0, maxTimes = 0;
    while ( list != NULL ) {
        if ( list->manyTimes > maxTimes) {
            maxTimes = list->manyTimes;
            maxElement = list->value;
        }
        list = list->next;
    }
    return maxElement;
}

int majorityElement(int* nums, int numsSize) {
    lista *list = ( lista * ) malloc ( sizeof ( lista ) );
    list->value = nums[0];
    list->manyTimes = 1;
    list->next = NULL;
    for ( int count = 1; count < numsSize; count++ ) {
        addToList ( nums[count], &list );
    }
    int result = majorElement ( list, numsSize );

    lista *ptr;
    while ( list->next != NULL ){
        ptr = list->next;
        list->next = list->next->next;
        free ( ptr );
    }
    free ( list );
    return result;
}

int main(int argc, char const *argv[])
{
    int numsSize;
    printf ( "Digite o tamanho do vetor: \n" );
    scanf ( "%d", &numsSize );
    int nums[numsSize];
    for ( int count = 0; count < numsSize; count++ ) {
        printf ( "\nDigite o %d° elemento: ", count + 1 );
        scanf ( "%d", &nums[count] );
    }

    printf("%d\n", majorityElement(nums, numsSize));

    return 0;
}