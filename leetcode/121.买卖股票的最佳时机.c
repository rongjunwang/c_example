/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
//贪心算法
int maxProfit(int* prices, int pricesSize){

    if(pricesSize == 0 || pricesSize == 1) return 0;

    int min = INT_MAX;
    int max = INT_MIN;

    for(int i=0;i<pricesSize;i++){
        //寻找最小值
        min = min>prices[i] ? prices[i] : min;

        //计算当前距离最大值
        max = max>(prices[i]-min) ? max : prices[i]-min;
    }
    return max;
}


// @lc code=end

