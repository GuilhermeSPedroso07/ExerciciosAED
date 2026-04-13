#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    for ( int c = 1; c < numsSize; c++ ) {
        if ( nums[c] == nums[c-1] ) {
            for ( int d = c; d < numsSize - 1; d++ ) {
                nums [d] = nums[d+1];
            }
            c--;
            numsSize--;
        }
    }
    return numsSize;
}

int main(int argc, char const *argv[])
{
    int numsSize = 10;
    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
    int result = removeDuplicates(nums, numsSize);
    printf ( "%d\n", result);
    for (int a = 0; a < numsSize -1; a++) {
        printf("%d", nums[a]);
    }
}
