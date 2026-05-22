typedef struct list {
    int value;
    int manyTimes;

    struct list *next;
} list;

void addToList ( int num, list **list ) {
    while ( ( *list ) ->value != num ) {
        if ( ( *list ) ->next == NULL ) {
            ( *list ) ->next = malloc ( sizeof ( list ) );
            ( *list ) ->next->value = num;
        }
        ( *list ) = ( *list ) ->next;
    }
    ( *list ) ->manyTimes++;
}

int majorElement ( list *list, int n ) {
    while ( list->manyTimes < n/2 ) {
        list = list->next;
    }
    return list->value;
}

int majorityElement(int* nums, int numsSize) {
    list *list = malloc ( sizeof ( list ) );
    list->value = nums[0];
    list->manyTimes = 1;
    for ( int count = 1; count < numsSize; count++ ) {
        addToList ( nums[count], &list );
    }
    return majorElement ( list, numsSize );
}
