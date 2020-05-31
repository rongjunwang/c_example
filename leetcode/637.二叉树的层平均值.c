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

void levelOrderTree(struct TreeNode* root,int level, double* res){
    if(root){
        res[level] = res[level] == 0 ? root->val : (res[level]+root->val)/2;
        printf("%lf\n",res[level]);
        levelOrderTree(root->left, level+1, res);
        levelOrderTree(root->right, level+1, res);
    }
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int* level = malloc(sizeof(int));
    getTreeDepth(root, 0, level);
    *returnSize = *level;
    
    double* res = malloc((*level) * sizeof(double));
    memset(res, NULL, sizeof(double) * (*level));
    levelOrderTree(root,0,res);
    return res;
}


// @lc code=end

