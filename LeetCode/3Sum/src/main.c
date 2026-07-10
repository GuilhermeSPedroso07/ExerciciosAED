#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void quickSort ( int *nums, int left, int right ) {
    int pivot = nums[ ( rand ( ) % ( right - left ) ) + left ];
    int i = left;
    int j = right;
    int temp;

    do {
        while ( nums[i] < pivot ) {
            i++;
        }
        while ( pivot < nums[j] ) {
            j--;
        }

        if ( i <= j ) {
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j--;
        }
    } while ( i <= j );

    if ( j > left ) {
        quickSort ( nums, left, j );
    }
    if ( i < right ) {
        quickSort ( nums, i, right );
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = 0;
    if ( numsSize < 3 ) {
        return NULL;
    }
    quickSort ( nums, 0, numsSize - 1 );
    for ( int i = 0; i < numsSize; i++ ) {
        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );
    int capacidade = numsSize;
    int **returnNums = ( int ** ) malloc ( sizeof ( int * ) * capacidade );
    int i = 0, j = 1, k = numsSize - 1;
    int last;

    while ( i < numsSize - 2 ) {
        while ( j < k ) {
            while ( nums[i] + nums[j] + nums[k] < 0 && j < k ) {
                j++;
            }
            while ( nums[i] + nums[j] + nums[k] > 0 && k > j ) {
                k--;
            }

            if ( nums[i] + nums[j] + nums[k] == 0 && j != k ) {
                if ( *returnSize == capacidade ) {
                    capacidade *= 2;
                    returnNums = realloc ( returnNums, sizeof ( int * ) * capacidade );
                }
                returnNums[*returnSize] = malloc ( sizeof ( int ) * 3 );
                returnNums[*returnSize][0] = nums[i];
                returnNums[*returnSize][1] = nums[j];
                returnNums[*returnSize][2] = nums[k];

                ( *returnSize ) += 1;
                last = nums[j];
                j++;
                while ( j < k && nums[j] == last ) {
                    j++;
                }
                last = nums[k];
                k--;
                while ( j < k && nums[k] == last ) {
                    k--;
                }

            } else if ( nums[i] + nums[j] + nums[k] < 0 ) {
                j++;
            } else {
                k--;
            }
        last = nums[i];
        }
        i++;
        while ( i < k && nums[i] == last ) {
            i++;
        }
        j = i + 1;
        k = numsSize - 1;
    }
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for ( int i = 0; i < ( *returnSize ); i++ ) {
        (*returnColumnSizes)[i] = 3;
    }
    return returnNums;
}

int main(int argc, char const *argv[])
{
    srand ( time ( NULL ) );
    int numsSize = ( rand ( ) % 20 ) + 1;
    int *nums = ( int * ) malloc ( sizeof ( int ) * numsSize );
    int returnSize, *returnSizes;

    for ( int i = 0; i < numsSize; i++ ) {
        nums[i] = ( rand ( ) % 20 ) - 10;
    }
    for ( int i = 0; i < numsSize; i++ ) {
        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );
    int **result = threeSum ( nums, numsSize, &returnSize, &returnSizes );

    for ( int i = 0; i < returnSize; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            printf ( "%d ", result[i][j]);
        }
        printf ( "\n" );
    }

    return 0;
}
