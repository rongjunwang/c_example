/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 */

// @lc code=start


int minDistance(char * word1, char * word2){
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    if(word1_len == 0) return word2_len;
    if(word2_len == 0) return word1_len;

    int dp[word1_len+1][word2_len+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 0;
    for (int i = 1; i <= word1_len; i++)
    {
        dp[i][0] =  dp[i-1][0] + 1;
    }

    for (int j = 1; j <= word2_len; j++)
    {
        dp[0][j] = dp[0][j-1] + 1;
    }

    for (int i = 1; i <= word1_len; i++)
    {
        for (int j = 1; j <= word2_len; j++)
        {
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1; 
            }
        }
        
    }
    return dp[word1_len][word2_len];

}

int min(int num1,int num2,int num3){
    if(num1 < num2){
        if(num1 < num3){
            return num1;
        }else{
            return num3;
        }
    }else{
        if(num2 < num3){
            return num2;
        }else{
            return num3;
        }
    }
}


// @lc code=end

