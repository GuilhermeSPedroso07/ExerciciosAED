#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *output = ( int * ) malloc ( sizeof ( int ) * 2 );
    output[0] = -1;
    output[1] = -1;
    *returnSize = 2;

    for ( int i = 0; i < numsSize; i++ ) {
        if ( nums[i] == target ) {
            if ( output[0] == -1 ) {
                output[0] = i;
            }
            output[1] = i;
        }
    }

    return output;
}

int main(int argc, char const *argv[])
{
    srand ( time ( NULL ) );
    int numsSize = rand ( ) % 20 + 1;
    int returnSize;
    int *nums = ( int * ) malloc ( sizeof ( int ) * numsSize );

    for ( int i = 0; i < numsSize; i++ ) {
        nums[i] = rand ( ) % 20;
    }

    for ( int i = 0; i < numsSize; i++ ) {
        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );

    int *range = searchRange ( nums, numsSize, 2, &returnSize );

    for ( int i = 0; i < returnSize; i++ ) {
        printf ( "%d ", range[i] );
    }

    free ( range  );
    free ( nums );

    return 0;
}
