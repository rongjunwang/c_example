/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
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

bool inSortTree(struct TreeNode* root,long long* prev){
    if(root){
        if(!inSortTree(root->left,prev)) return false;

        if(root->val <= *prev) return false;
        *prev = root->val;  

       if(!inSortTree(root->right,prev)) return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root){
    long long pre = LONG_MIN;
    return inSortTree(root, &pre);
}


// @lc code=end

