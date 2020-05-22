/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start


//双指针
int maxArea(int* height, int heightSize){
    if(heightSize == 0) return 0;
    int maxArea = 0;
    int left = 0;
    int right = heightSize - 1;
    int temp;

    while(left != right){
        //短的一侧移动，找寻更高的
        if(height[left] > height[right]){
            temp = height[right] * (right - left);
            right--;
        }else{
            temp = height[left] * (right - left);
            left++;
        }

        maxArea = temp > maxArea ? temp : maxArea;
    }

    return maxArea;
}


// @lc code=end

