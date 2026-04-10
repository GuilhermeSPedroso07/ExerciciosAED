int searchInsert(int* nums, int numsSize, int target) {
    for ( numsSize; numsSize > 0; numsSize--) {
        if ( nums[numsSize - 1] == target ) {
            return numsSize - 1;
        }
        if ( nums[numsSize - 1] < target ) {
            return numsSize;
        }
    }
    return 0;
}
