/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** res = calloc(n,sizeof(int*));
    *returnSize = n;
    int c = 1, i= 0, j=0;

    for(i=0;i<n;i++){
        res[i] = calloc(n,sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    while(c <= n*n){
        for(i=j;i<n-j;i++) res[j][i] = c++;
        for(i=j+1;i<n-j;i++) res[i][n-j-1] = c++;
        for(i=n-j-2;i>=j;i--) res[n-j-1][i] = c++;
        for(i=n-j-2;i>j;i--) res[i][j] = c++;
        j++;
    }
    return  res;
}


// @lc code=end

