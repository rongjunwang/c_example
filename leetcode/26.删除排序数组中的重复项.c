/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    
    int j=0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[j] != nums[i]){
            nums[++j] = nums[i];
        }
    }
    
    return ++j;
    
}


// @lc code=end

