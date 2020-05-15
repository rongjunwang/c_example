/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize < 3) return returnColumnSizes;
    if(numsSize == 3){
        if(nums[0] + nums[1] + nums[2] == 0){
            returnColumnSizes[0] = nums;
        }

        return returnColumnSizes;
    } 
    //排序+双指针
    sort(*nums,*nums+numsSize);
    int i,j;
    for(int k=0;k<numsSize;k++){
        i = k+1;
        j = numsSize - 1;

        for (i = k+1; i < j; j++)
        {
            if(nums[i] + nums[j] + nums[k] == 0){
                int* temp = (int*)malloc(sizeof(int));
                temp[0] = nums[0];
            }
        }
        

    }
}


// @lc code=end

