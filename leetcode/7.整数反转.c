/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    long a = 0;
    while(x != 0){
        a = x%10 + a*10; 
        x=x/10;
    }
    
    if(a > 2147483647 || a < -2147483648){
        return 0;
    }

    return a;
}


// @lc code=end

