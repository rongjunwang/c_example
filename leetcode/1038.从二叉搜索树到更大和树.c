/*
 * @lc app=leetcode.cn id=1038 lang=c
 *
 * [1038] 从二叉搜索树到更大和树
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

//中序遍历
struct TreeNode* bstTo(struct TreeNode* root, int* sum){
    if(root){
        bstTo(root->right, sum);
        *sum += root->val;
        root->val = *sum;
        bstTo(root->left, sum);
    }
    return root;
}

struct TreeNode* bstToGst(struct TreeNode* root){
    int sum = 0;
    return bstTo(root, &sum);
}




// @lc code=end

