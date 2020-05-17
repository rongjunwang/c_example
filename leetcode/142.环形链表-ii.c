/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
   

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    //判断是否有环
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) break;
    }

    if(fast == NULL || fast->next == NULL) return 0;
    
    //找到环的起点
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
// @lc code=end

