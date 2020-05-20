/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* temp = head;
    struct ListNode* current = head;
    struct ListNode* pre = NULL;

    while(current != NULL){
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }

    return pre;
    
}


// @lc code=end

