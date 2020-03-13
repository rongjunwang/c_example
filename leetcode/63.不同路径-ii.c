/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if( *(*(obstacleGrid)) == 1) return 0;
    if( *(*(obstacleGrid+obstacleGridSize-1) + *obstacleGridColSize-1) == 1) return 0;

    unsigned int dp[obstacleGridSize+1][*obstacleGridColSize+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 1; i < obstacleGridSize; i++)
    {   
        dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
    }

    for (int j = 1; j < *obstacleGridColSize; j++)
    {
        dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];
    }

    for (int i = 1; i < obstacleGridSize; i++)
    {
        for (int j = 1; j < *obstacleGridColSize; j++)
        {
            dp[i][j] = (obstacleGrid[i-1][j] == 1?0:dp[i-1][j]) 
                      +(obstacleGrid[i][j-1] == 1?0:dp[i][j-1]);
        }
    }

    return dp[obstacleGridSize-1][*obstacleGridColSize-1];
}


// @lc code=end

