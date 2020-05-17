/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k==0 || head == NULL) return head;

    struct ListNode* p = head;
    int sum = 1;
    while(p->next != NULL){
        p = p->next;
        sum++;
    }
    if(sum==k) return head;

    if(sum<k) k = k%sum;
    p->next = head;
    //printf("%d-%d-%d-%d\n",p->val,head->val,head->next->val,sum);

    p = head;
    int end = sum - k; 
    for(int i=1;i<end;i++){
        p = p->next;
        if(p->next == NULL) p=head;
    }
    //printf("%d-%d-%d-%d\n",end,p->val,head->val,head->next->val);
    head = p->next;
    p->next = NULL;
    //printf("%d-%d-%d-%d\n",end,p->val,head->val,head->next->val);

    return head;
}


// @lc code=end

