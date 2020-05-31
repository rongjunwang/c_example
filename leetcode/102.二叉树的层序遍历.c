/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void get_tree_depth(struct TreeNode* root,int temp, int* layer){
    temp++;
    if(temp > *layer) *layer = temp;
    if(root->left) get_tree_depth(root->left, temp, layer);
    if(root->right) get_tree_depth(root->right, temp, layer);
}

void get_tree_row(struct TreeNode* root,int layer, int p[]){
    p[layer]++;
    if(root->left) get_tree_row(root->left,layer+1,p);
    if(root->right) get_tree_row(root->right,layer+1,p);
}

void get_tree_value(struct TreeNode* root, int layer, int* p[]){
    printf("pp-%p\n",p);
    *p[layer] = root->val;
    p[layer]++;
    printf("ppp-%p\n",p[layer]);
    if(root->left) get_tree_value(root->left, layer+1, p);
    if(root->right) get_tree_value(root->right, layer+1, p);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(!root) return 0;

    get_tree_depth(root, 0, returnSize);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    memset(*returnColumnSizes,0,(*returnSize) * sizeof(int));
    get_tree_row(root, 0, *returnColumnSizes);

    int** res = malloc(*returnSize * sizeof(int*));
    int** p = malloc(*returnSize * sizeof(int*));
    for(int i=0;i<(*returnSize);i++){
        p[i] = res[i] = malloc((*returnColumnSizes)[i] * sizeof(int));
    }
    printf("p=%p\n",p);
    get_tree_value(root, 0, p);
    free(p);
    return res;
}


// @lc code=end

