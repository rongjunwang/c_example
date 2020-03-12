/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start


int minPathSum(int** grid, int gridSize, int* gridColSize){
    unsigned int dp[gridSize+1][*gridColSize+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++)
    {   
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for (int j = 1; j < *gridColSize; j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    unsigned result;
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = 1; j < *gridColSize; j++)
        {
            dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i][j-1]:dp[i-1][j]) + grid[i][j];
        }
    }

    return dp[gridSize-1][*gridColSize-1];
}


// @lc code=end

