/*
 * @lc app=leetcode.cn id=148 lang=c
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//归并算法
struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;

    //快慢指正找中间点
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* pre  = head;
    while(fast != NULL && fast->next != NULL){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    } 
    pre->next = NULL;
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(slow);

    //合并
    struct ListNode* h = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* res = h;
    while(left != NULL && right != NULL){
        if(left->val < right->val){
            h->next = left;
            left = left->next;
        }else{
            h->next = right;
            right = right->next;
        }
        h = h->next;
    } 
    h->next = left != NULL ? left : right;
    return res->next;
}


// @lc code=end

