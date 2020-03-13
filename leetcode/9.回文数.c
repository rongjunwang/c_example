/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


bool isPalindrome(int x){
    if(x < 0){
        return false;
    }
    long result = 0;
    int a=x;
    while(x!=0){
        result = x%10 + result*10;
        x = x/10;
    }

    if(result == a){
        return true;
    }else{
        return false;
    }

}


// @lc code=end

