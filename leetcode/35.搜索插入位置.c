/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
    if(numsSize == 0) return 0;

    for (int i = 0; i < numsSize; i++)
    {
        if(*(nums+i) >= target){
            return i;
        }
    }
    return numsSize;
    
}


// @lc code=end

