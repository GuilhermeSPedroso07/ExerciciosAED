#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort ( int data[], int left, int right ) {
    int tmp, pivot, i, j;
    i = left;
    j = right;
    pivot = data[ ( rand ( ) % ( right - left ) ) + left];

    do {
        while ( data[i] < pivot ) {
            i++;
        }
        while ( pivot < data[j] ) {
            j--;
        }

        if ( i <= j ) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;

            i++;
            j--;
        }
    } while ( i <= j );
    if ( i < right ) {
        quickSort ( data, i, right );
    }
    if ( left < j ) {
        quickSort ( data, left, j );
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if ( numsSize < 2 ) {
        return nums;
    }
    quickSort ( nums, 0, numsSize - 1 );
    return nums;
}

int main(int argc, char const *argv[])
{
    srand ( time ( NULL ) );
    int numsSize = rand ( ) % 20 + 1;
    int *nums = ( int * ) malloc ( sizeof ( int ) * numsSize );

    for ( int i = 0; i < numsSize; i++ ) {
        nums[i] = rand ( ) % 20;
        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );

    nums = sortArray ( nums, numsSize, &numsSize );

    for ( int i = 0; i < numsSize; i++ ) {
        printf ( "%d ", nums[i] );
    }

    free ( nums );

    return 0;
}
