/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compareByInstance(int *a,int *b){
    return *a - *b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int** returnValue = (int**)malloc(sizeof(int*) * (numsSize*numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize*numsSize));
    *returnSize = 0;

    if(numsSize < 4) return NULL;
    //排序+双指针
    qsort(nums, numsSize, sizeof(int), compareByInstance);
    int i,j,left,right,sum;
    for (j = 0; j < numsSize-1; j++)
    {
        if(j > 0 && nums[j-1] == nums[j]) continue;

        for (i = j+1; i < numsSize-1; i++)
        {
            if(i > j+1 && nums[i-1] == nums[i]) continue;

            left = i+1;
            right = numsSize - 1;
            while(left < right){
                sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum > target){
                    right--;
                }else if(sum < target){
                    left++;
                }else{
                    returnValue[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    returnValue[*returnSize][0] = nums[i];
                    returnValue[*returnSize][1] = nums[j];
                    returnValue[*returnSize][2] = nums[left];
                    returnValue[*returnSize][3] = nums[right]; 
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while(nums[left] == nums[++left] && left < right);
                    while(nums[right] == nums[--right] && left < right);
                }
            }
        }
    }

    return returnValue;
}


// @lc code=end

