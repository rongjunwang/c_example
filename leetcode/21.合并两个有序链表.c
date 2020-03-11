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

    struct ListNode* headnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    headnode->next = NULL;
    headnode->val = 0;

    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    temp->next = NULL;
    headnode = temp;

    while(l2 != NULL && l1 != NULL){

        if(l1->val < l2->val){
            temp->next = l1;
            l1 = l1->next; 
        }else{
           temp->next = l2;
           l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1 != NULL){
        temp->next = l1;
    }else if(l2 != NULL){
        temp->next = l2;
    }

    return headnode->next;
}


// @lc code=end

