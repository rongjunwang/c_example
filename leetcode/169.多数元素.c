/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start

int CompareByIncrease(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums,numsSize, sizeof(int),CompareByIncrease);
    return nums[numsSize/2];
}


// @lc code=end

