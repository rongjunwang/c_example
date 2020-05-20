/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* result = head;
    struct ListNode* first = result;
    struct ListNode* second = result;

    while(n > 0){
        first = first->next;
        n--;
    }
    if(first == NULL) return result->next;

    while (first->next != NULL){
        first = first->next;
        second = second->next; 
    }

    second->next = second->next->next;
    return result;
}


// @lc code=end

