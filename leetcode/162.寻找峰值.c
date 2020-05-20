/*
 * @lc app=leetcode.cn id=162 lang=c
 *
 * [162] 寻找峰值
 */

// @lc code=start


int findPeakElement(int* nums, int numsSize){
    if(numsSize == 1) return 0;

    int left = 0;
    int right = numsSize - 1;
    int mid;
    while(left < right){
        mid = (left+right)/2;
        if(nums[mid] > nums[mid+1]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}


// @lc code=end

