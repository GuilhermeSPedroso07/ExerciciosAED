#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort ( int nums[], int left, int right ) {
    int i, j, pivot, tmp;
    i = left;
    j = right;
    pivot = nums[ ( rand ( ) % ( right + 1 - left ) ) + left];

    do { 
        while ( nums[i] < pivot ) {
            i++;
        }
        while ( pivot < nums[j] ) {
            j--;
        }
        if ( i <= j ) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    } while ( i <= j );

    if ( left < j ) {
        quickSort ( nums, left, j );
    }
    if ( i < right ) {
        quickSort ( nums, i, right );
    }
}


int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int *output = NULL;
    if ( numsSize < 2 ) {
        *returnSize = 0;
        return output;
    }
    int count = 0;
    output = realloc ( output, sizeof ( int ) * ( numsSize / 2 ) );
    quickSort ( nums, 0, numsSize - 1 );
    for ( int i = 0; i < numsSize - 1; i++ ) {
        if ( nums[i] == nums[i + 1] ) {
            count++;
            output[count - 1] = nums[i];
            i++;
        }
    }
    output = realloc ( output, sizeof ( int ) * count );
    *returnSize = count;
    return output;
}

int main(int argc, char const *argv[])
{
    int returnSize;
    srand ( time ( NULL ) );
    int size = rand ( ) % 100 + 1;
    int *nums = ( int * ) malloc ( sizeof ( int ) * size );

    for ( int i = 0; i < size; i++ ) {
        nums[i] = rand ( ) % 100 + 1;

        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );

    int *duplicates = findDuplicates ( nums, size, &returnSize );

    for ( int i = 0; i < returnSize; i++ ) {
        printf ( "%d ", duplicates[i] );
    }

    free ( nums );
    free ( duplicates );

    return 0;
}
