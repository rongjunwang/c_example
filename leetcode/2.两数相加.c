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
    struct ListNode* headnode = NULL;
    headnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    headnode->next = NULL;
    headnode->val = 0;

    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    headnode = temp;
    int add = 0 ;

    while(l1 != NULL || l2 != NULL || add){

        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));

        if(l1 != NULL && l2 != NULL){
            newnode->next = NULL;
            newnode->val = l1->val + l2->val + add;
            l1 = l1->next;
            l2 = l2->next;
        }else if(l1 != NULL && l2 == NULL){
            newnode->next = NULL;
            newnode->val = l1->val + add;
            l1 = l1->next;
        }else if(l1 == NULL && l2 != NULL){
            newnode->next = NULL;
            newnode->val = l2->val + add;
            l2 = l2->next;
        }else{
            newnode->next = NULL;
            newnode->val = add;
        }

        //进位处理
        if(newnode->val >= 10){
            newnode->val = newnode->val % 10;
            add = 1;
        }else{
            add = 0;
        }

        temp->next = newnode;
        temp = temp->next;
    }

    return headnode->next;
}


// @lc code=end

