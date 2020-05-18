/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

//贪心算法
int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0 || pricesSize == 1) return 0;

    int sum = 0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i] - prices[i-1] > 0) 
            sum += prices[i] - prices[i-1];
    }
    return sum;
}


// @lc code=end

