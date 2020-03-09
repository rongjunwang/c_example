/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    int a = 0;
    while(x > 10 || x < -10){
        a = x%10 + a*10; 
        x=x/10;
    }
    a = a*10 + x;
    return a;
}


// @lc code=end

