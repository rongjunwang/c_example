/*
 * @lc app=leetcode.cn id=109 lang=c
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode* phead= head;
    struct ListNode* fast = phead;
    struct ListNode* slow = phead;
    struct ListNode* pre = phead;

    while(fast != NULL && fast->next != NULL){
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    if(phead->next == NULL){
        phead = NULL;
    }

    struct TreeNode* p = malloc(sizeof(struct TreeNode));
    p->val = slow->val;
    pre->next = NULL;
    p->left = sortedListToBST(phead);
    p->right = sortedListToBST(slow->next);
    return p;
}


// @lc code=end

