/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    //初始化
    *returnSize = 0;
    if(matrixSize == 0) return NULL;
    int *res = calloc(matrixSize * (*matrixColSize), sizeof(int));
    
    //row-行，column-列
    int r1 = 0,r2 = matrixSize - 1;
    int c1 = 0,c2 = (*matrixColSize) - 1;
    int i = 0;
    printf("%d-%d-%d-%d\n",r1,r2,c1,c2);

    while(c1 <= c2 && r1 <= r2){
        //第一行
        for(i=c1; i<=c2; i++){
            printf("1:%d-%d\n",r1,i);
            res[(*returnSize)++] = matrix[r1][i];
        }

        //最后一列
        for(i=r1+1; i<=r2; i++){
            printf("2:%d-%d\n",i,c2);
            res[(*returnSize)++] = matrix[i][c2];
        }
        
        if (r1 < r2 && c1 < c2) {
            //最后一行
            for(i=c2-1; i>=c1; i--){ 
                printf("3:%d-%d-%d\n",r2,i,matrix[r2][i]);
                res[(*returnSize)++] = matrix[r2][i];
            }

            //第一列
            for(i=r2-1; i>=r1+1; i--){ 
                printf("4:%d-%d-%d\n",i,c1,matrix[i][c1]);
                res[(*returnSize)++] = matrix[i][c1];
            }
        }

        //下一次循环
        c1++;
        c2--;
        r1++;
        r2--;
    }
    return res;
}


// @lc code=end

