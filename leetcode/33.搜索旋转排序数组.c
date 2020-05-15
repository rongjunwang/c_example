/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
    if(numsSize == 0) return -1;
    if(numsSize == 1) return target==nums[0] ? 0:-1;

    int left = 0;
    int right = numsSize - 1;
    int mid;
    while(left <= right){
        mid = (left+right) / 2;
        if(target == nums[mid]) return mid;
        if(nums[0] <= nums[mid]){
            if(nums[0] <= target && target < nums[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else{
            if(nums[mid] <= target && target < nums[0]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return -1;
}


// @lc code=end

