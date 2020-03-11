/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

//动态规划
int isMatch(char * s, char * p){
    int** dp;
    dp = (int **)malloc(sizeof(int *) * strlen(s));
    for(int i = 0; i < strlen(s); i++){
        dp[i] = (int *)malloc(sizeof(int) * strlen(p));
    }

    for (int i=0;i<strlen(s); i++)
    {
        for(int j=0;j<strlen(p);j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for(int j=1;j<strlen(p) - 1;j++)
    {
        if(p[j] == '*' && dp[0][j-1] == 1 )
        {
            dp[0][j+1] = 1;
        }else{
            dp[0][j] = 0;
        }
    }
    for (int i=0;i<strlen(s); i++)
    {
        for(int j=1;j<strlen(p);j++)
        {
            if(p[j] == s[i]){
                dp[i][j] = dp[i-1][j-1];
            }else if(p[j] == '*'){
                if(p[j-1] == s[i] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j];
                }else if(p[j-1] != s[i]){
                    dp[i][j] = dp[i-1][j-2];
                }else{
                    return 0;
                }
            }else{
                return 0;
            }
        }
    }

    return dp[strlen(s)-1][strlen(p)-1];
}


// @lc code=end

