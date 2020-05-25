/*
 * @lc app=leetcode.cn id=238 lang=c
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize == 0 || numsSize == 1) return nums;

    int* res = calloc(numsSize,sizeof(int));
    //左边累计想乘
    int i;
    res[0] = 1;
    for(i=1;i<numsSize;i++){
        res[i] = res[i-1] * nums[i-1];
    }

    //右边累计相乘
    int value = 1;
    for(i=numsSize-1;i>=0;i--){
        res[i] *= value;
        value *= nums[i];
    }

    return res;
}


// @lc code=end

