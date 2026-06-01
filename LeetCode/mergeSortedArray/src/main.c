#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int index1 = 0, index2 = 0;
    int * arrayTemp = ( int * ) malloc ( sizeof ( int ) * ( n + m ) );

    for ( int i = 0; i < n + m; i++ ) {
        if ( index1 == m ) {
            arrayTemp[i] = nums2[index2];
            index2++;
        } else if ( index2 == n ) {
            arrayTemp[i] = nums1[index1];
            index1++;
        } else {
            if ( nums1[index1] < nums2[index2] ) {
                arrayTemp[i] = nums1[index1];
                index1++;
            } else {
                arrayTemp[i] = nums2[index2];
                index2++;
            }
        }
        
    }
    for ( int c = 0; c < nums1Size; c++ ) {
            nums1[c] = arrayTemp[c];
        } 
    free(arrayTemp);
}

int main(int argc, char const *argv[])
{
    int nums1[6] = {1,2,3};
    int nums2[3] = {2, 5, 6};
    int m = 3, n = 3;
    printf ( "\n");

    for ( int c = 0; c < 6; c++ ) {
        printf ( "%d", nums1[c] );
    }
    merge(nums1, 6, m, nums2, 3, n);
    printf ( "\n");

    for ( int c = 0; c < 6; c++ ) {
        printf ( "%d", nums1[c] );
    }


    return 0;
}
