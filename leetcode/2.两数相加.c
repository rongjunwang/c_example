/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result;
    struct ListNode* temp = NULL;
    while(l1->next != NULL){
        if(l1 != NULL && l2 != NULL){
            result->val = l1->val + l2->val;
            result->next = &temp;
        }
        temp = result;
        l1 = l1->next;
        l2 = l2->next;
    }
    return result;
}


// @lc code=end

