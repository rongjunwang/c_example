/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 100
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * MAX_SIZE);
    int* temp = (int*)calloc(numsSize, sizeof(int));
    staceback(0, 0, nums, numsSize, temp, result, returnSize, returnColumnSizes);
    return result;
}

void staceback(int index,int current, int* nums, int numsSize, int* temp, int** result, int* resturnSize, int** returnColumnSizes){
    for(int i=current;i<numsSize;i++){
        temp[index] = nums[i];
        staceback(index + 1,current + 1,nums,numsSize,temp,result,resturnSize,returnColumnSizes);
    }

    result[(*resturnSize)] = (int*)calloc(numsSize, sizeof(int));
    memcpy(result[(*resturnSize)], temp, sizeof(int) * numsSize);
    (*resturnSize)++;
    returnColumnSizes[(*resturnSize)] = index;
}


// @lc code=end

