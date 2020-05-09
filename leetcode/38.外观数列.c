/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 外观数列
 */

// @lc code=start


char * countAndSay(int n){
    char** dp = (char**)malloc(sizeof(char*) * n);
    for (int i = 1; i < n; i++)
    {
        dp[i] = (char*)malloc(sizeof(char)*100); 
    }

    dp[0] = "1";

    int count = 0;
    int i,j;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j< strlen(dp[i-1]); j++)
        {
            if(dp[i-1][j] == dp[i-1][j-1]){
                count++;
            }else{
                dp[i][j] = count + dp[i-1][j];
            }
            printf("%d-%c\n",count,dp[i][j]);
        }
        printf("%d\n",strlen(dp[i-1]));
        dp[i][j+1] = '\0';
    }
    
    
    return dp[n-1];
}


// @lc code=end

