/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* returnValue = (int*)malloc(sizeof(int) * 2);
    returnValue[0] = -1;
    returnValue[1] = -1;
    *returnSize = 2;

    if(numsSize == 0) return returnValue;
    if(numsSize == 1){
        if(target == nums[0]){
            returnValue[0] = 0;
            returnValue[1] = 0;
        }

        return returnValue;
    }

    int left = 0;
    int right = numsSize - 1;
    int mid;
    while(left <= right){
        mid =  (left+right)/2;

        //找到target
        if(target == nums[mid]){
            int leftFlage = 0;
            int rightFlage = 0;
            left = right = mid;
            printf("%d\n", mid);
            while(1){
                if( left > 0  && nums[left-1] == target){
                    left--;
                }else{
                    leftFlage = 1;
                }

                if(right < numsSize-1 && nums[right+1] == target){
                    right++;
                }else{
                    rightFlage = 1;
                }

                if(leftFlage == 1 && rightFlage == 1){
                    returnValue[0] = left;
                    returnValue[1] = right;
                    break;
                }

                printf("%d-%d-%d-%d-%d-%d\n", returnValue[0], returnValue[1], left, right, leftFlage, rightFlage);
            }
            break;
        }

        if(nums[0] <= target && target < nums[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return returnValue;
}


// @lc code=end

