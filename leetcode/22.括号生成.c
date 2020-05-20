/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1500
char ** generateParenthesis(int n, int* returnSize){
    char** result = (char**)calloc(MAX_SIZE, sizeof(char*));
    char* str = (char*)calloc((2 * n + 1), sizeof(char));
    *returnSize = 0;
    traceback(0, 0, 0, n, str, result, returnSize);
    return result;
}

void traceback(int left, int right, int index, int n, char* str, char** result,int* returnSize){
    if(left == n && right == n){
        result[(*returnSize)] = (char*)calloc((2 * n + 1), sizeof(char));
        strcpy(result[(*returnSize)++],str);
        return;
    }

    if(left < n){
        str[index] = '(';
        traceback(left+1, right, index+1, n, str, result, returnSize);
    }

    if(left > right && right < n){
        str[index] = ')';
        traceback(left, right+1, index+1, n, str, result, returnSize);
    }
}


// @lc code=end

