/*
 * @lc app=leetcode.cn id=637 lang=c
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void getTreeDepth(struct TreeNode* root,int temp,int* level){
    if(root){
        temp++;
        if(temp > *level) *level = temp;
        getTreeDepth(root->left, temp, level);
        getTreeDepth(root->right, temp, level);
    }
}

void levelOrderTree(struct TreeNode* root,int level,int* flag, double* res){
    if(root){
        res[level] += root->val;
        flag[level] += 1;
        levelOrderTree(root->left, level+1, flag, res);
        levelOrderTree(root->right, level+1, flag, res);
    }
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    if(!root){
        *returnSize = 0;
        double* res = NULL;
        return res;
    }
    
    int* level = malloc(sizeof(int));
    getTreeDepth(root, 0, level);
    *returnSize = *level;
    
    double* res = malloc((*level) * sizeof(double));
    int* flag = malloc((*level) * sizeof(int));
    memset(res, 0, sizeof(double) * (*level));
    memset(flag, 0, sizeof(int) * (*level));
    levelOrderTree(root, 0, flag, res);

    for(int i=0;i<*level;i++){
        res[i] = res[i] / flag[i];
    }

    return res;
}


// @lc code=end

