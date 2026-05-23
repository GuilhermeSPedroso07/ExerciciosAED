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
            ptr->next = malloc ( sizeof ( list ) );
            ptr->next->value = num;
        }
        ptr = ptr->next;
    }
    ptr->manyTimes++;
}

int majorElement ( lista *list, int n ) {
    while ( list->manyTimes < ( n/2 ) ) {
        list = list->next;
    }
    return list->value;
}

int majorityElement(int* nums, int numsSize) {
    lista *list = malloc ( sizeof ( list ) );
    list->value = nums[0];
    list->manyTimes = 1;
    for ( int count = 1; count < numsSize; count++ ) {
        addToList ( nums[count], &list );
    }
    return majorElement ( list, numsSize );
}

int main(int argc, char const *argv[])
{
    int nums[5] = {3,4,4,4,2};
    int numsSize = 5;

    printf("%d\n", majorityElement(nums, numsSize));

    return 0;
}
