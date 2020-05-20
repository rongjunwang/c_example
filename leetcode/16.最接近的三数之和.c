/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

//排序+双指针

int CompareByIncrease(int *a,int *b)
{
    return *a - *b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    if(numsSize < 3) return -1;

    qsort(nums, numsSize, sizeof(int), CompareByIncrease);
    int left;
    int right;
    int sum;
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize; i++)
    {
        left = i+1;
        right = numsSize - 1;
        while(left < right){
            sum = nums[i] + nums[left] + nums[right];
            if(abs(sum - target) < abs(res - target)){
                res = sum;
            }
            
            if(sum > target){
                right--;
            }else if(sum < target){
                left++;
            }else{
                return target;
            }
        }
    }
    return res;
}


// @lc code=end

