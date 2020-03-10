/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    struct ListNode* headnode = NULL;
    headnode->next = NULL;
    headnode->val = 0;

    struct ListNode* temp = NULL; 
    temp->next = NULL;
    headnode->next = temp;

    while(l2 != NULL || l1 != NULL){

        if(l1->val > l2->val){
            temp->val = l1->val;
            l1 = l1->next;

            temp = temp->next;
            temp->val = l2->val;
            temp->next = NULL;
            l2 = l2->next;
        }else{
            temp->val = l2->val;
            l2 = l2->next;

            temp = temp->next;
            temp->val = l1->val;
            temp->next = NULL;
            l1 = l1->next;
        }
    }

    return headnode->next;
}


// @lc code=end

