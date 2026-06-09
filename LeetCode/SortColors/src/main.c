#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort ( int data[], int left, int right ) {
    int pivot, tmp, i, j;
    i = left;
    j = right;
    pivot = data[ ( rand () % ( right - left ) ) + left];

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

    if ( left < j ) {
        quickSort ( data, left, j );
    }
    if ( i < right ) {
        quickSort ( data, i, right );
    }
}

void sortColors(int* nums, int numsSize) {
    if ( numsSize < 2 ) {
        return;
    }
    quickSort ( nums, 0, numsSize - 1 );
}

int main(int argc, char const *argv[])
{
    srand( time ( NULL ) );

    int size = ( rand ( ) % 20 ) + 1;
    int *nums = ( int * ) malloc ( sizeof ( int ) * size );
    for ( int i = 0; i < size; i++ ) {
        nums[i] = rand ( ) % 3;
    }
    for ( int i = 0; i < size; i++ ) {
        printf ( "%d ", nums[i] );
    }
    printf ( "\n" );
    sortColors( nums, size );

    for ( int i = 0; i < size; i++ ) {
        printf ( "%d ", nums[i] );
    }
    free ( nums );
}
