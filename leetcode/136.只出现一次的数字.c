/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 */

// @lc code=start


int singleNumber(int* nums, int numsSize){
    int ans = nums[0];
    if (numsSize > 1) {
        for (int i = 1; i < numsSize; i++) {
            ans = ans ^ nums[i];
        }
    }
    return ans;
}


// @lc code=end

