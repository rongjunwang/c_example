/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

//动态规划
bool isMatch(char * s, char * p){
    int sl = strlen(s);
    int pl = strlen(p);
    bool dp[sl + 1][pl + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = sl; i > -1; --i) {
        for (int j = pl; j > -1; --j) {
            if (i == sl && j == pl) {
                dp[i][j] = true;
                continue;
            }
            if (pl - j > 1 && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] || (i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j]);
            } else {
                dp[i][j] = i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j + 1];
            }
        }
    }
    return dp[0][0];
}


// @lc code=end

