#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAM 20

void quickSort ( int data[], int left, int right ) {
    int tmp, pivot;
    int i = left;
    int j = right;
    pivot = data[ ( rand ( ) % (right - left ) ) + left];

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

bool containsDuplicate(int* nums, int numsSize) {
    if ( numsSize < 2 ) {
        return false;
    }
    quickSort ( nums, 0, numsSize - 1 );

    for ( int i = 0; i < numsSize - 1; i++ ) {
        if ( nums[i] == nums[i + 1] ) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    srand ( time ( NULL ) );
    int *data = ( int * ) malloc ( sizeof ( int ) * TAM );
    for ( int i = 0; i < TAM; i++ ) {
        data[i] = ( rand ( ) % 100 ) + 1;
    }
    for ( int i = 0; i < TAM; i++ ) {
        printf ( "%d ", data[i] );
    }
    printf ( "\n" );

    printf ( "\n%d\n", containsDuplicate ( data, TAM ) );

    for ( int i = 0; i < TAM; i++ ) {
        printf ( "%d ", data[i] );
    }

    free ( data );

    return 0;
}
