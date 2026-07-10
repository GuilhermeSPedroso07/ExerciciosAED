#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define sum(nums,i,j,k) (nums[i] + nums[j] + nums[k])
void quickSort ( int data[], int left, int right ) {
    int i = left;
    int j = right;
    int pivot = data[ ( rand ( ) % ( right - left ) ) + left];
    int temp;

    do {
        while ( data[i] < pivot ) {
            i++;
        }
        while ( pivot < data[j] ) {
            j--;
        }

        if ( i <= j ) {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            i++;
            j--;

        }
    } while ( i <= j );

    if ( j > left ) {
        quickSort ( data, left, j );
    }
    if ( right > i ) {
        quickSort ( data, i, right );
    }
}

int threeSumClosest(int* nums, int numsSize, int target) {
    quickSort ( nums, 0, numsSize - 1 );

    int i = 0;
    int j = 1;
    int k = numsSize - 1;
    int closestSum = sum(nums,0,1,2);
    while ( i < numsSize - 2 ) {
        while ( j < k ) {
            int current = sum(nums,i,j,k);
            if ( abs ( current - target) < abs ( closestSum - target ) ) {
                closestSum = current;
            }
            if ( current < target ) {
                j++;
            } else if ( current > target ) {
                k--;
            } else {
                return current;
            }
        }
        i++;
        j = i + 1;
        k = numsSize - 1;
    }
    return closestSum;
}

int main(int argc, char const *argv[])
{
    srand ( time ( NULL ) );
    int numsSize = ( rand ( ) % 18 ) + 3;
    int *nums = ( int * ) malloc ( sizeof ( int ) * numsSize );
    for ( int i = 0; i < numsSize; i++ ) {
        nums[i] = ( rand ( ) % 20 ) - 10; 
    }
    for ( int i = 0; i < numsSize; i++ ) {
        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );
    int target = ( rand ( ) % 20 ) - 10;
    printf ( "%d", target );
    printf ( "\n" );
    printf ( "%d", threeSumClosest ( nums, numsSize, target ) );

    return 0;
}
