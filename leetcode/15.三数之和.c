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
int CompareByIncrease(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; // 快排构造递增序列
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** returnValue = (int**)malloc(sizeof(int*) * ( numsSize * numsSize ));
    *returnColumnSizes = (int*)malloc(sizeof(int) * ( numsSize * numsSize ));
    *returnSize = 0;

    if(numsSize < 3) return NULL;

    //排序+双指针
    qsort(nums, numsSize, sizeof(int), CompareByIncrease);
    int left,right,result;
    for(int i=0;i<numsSize - 1;i++){
        if(nums[i] > 0) break;
        if(i>0 && nums[i] == nums[i-1]) continue;

        left = i+1;
        right = numsSize - 1;
        //printf("%d+%d+%d\n",nums[i],left,right);
        while(right > left){
            result = nums[i] + nums[left] + nums[right];
            //printf("%d\n",result);
            //printf("%d+%d+%d+%d+%d+%d\n",i,left,right,nums[i],nums[left],nums[right]);
            if(result == 0){
                returnValue[*returnSize] = (int*)malloc(sizeof(int) * 3);
                returnValue[*returnSize][0] = nums[i];
                returnValue[*returnSize][1] = nums[left];
                returnValue[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
               
                while( nums[left] == nums[++left] && right > left);     //往后去重
                while( nums[right] == nums[--right] && right > left);   //往前去重
            }else if(result > 0){
               right--;
            }else{
               left++;
            }
        }
    }

    return returnValue;
}


// @lc code=end

