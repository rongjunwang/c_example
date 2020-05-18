/*
 * @lc app=leetcode.cn id=123 lang=c
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start

#define max(a,b) (a>b?a:b);
int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0) return 0;
    int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
        
    for(int i=1;i<pricesSize;++i) {            
        s1 = max(s1, -prices[i]);
        s2 = max(s2, s1+prices[i]);
        s3 = max(s3, s2-prices[i]);
        s4 = max(s4, s3+prices[i]);
    }
    return max(0,s4);
}


// @lc code=end

