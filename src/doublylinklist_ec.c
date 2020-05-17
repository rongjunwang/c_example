/**
 * 双端链表
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct DoubleLinkListNode{
    struct DoubleLinkListNode* pre;
    struct DoubleLinkListNode* next;
    int data;
} DLNode;

typedef struct DoubleLinkList{
    struct DoubleLinkListNode* head;
    struct DoubleLinkListNode* tail;

    int size;
} DLlist;

//初始化链表
void init(DLlist* plist){
    plist->head = plist->tail = NULL;
    plist->size = 0;
}

//添加到链表首部
void add(DLlist *plist,int value){
    DLNode* dlnode = (DLNode*)malloc(sizeof(DLNode));
    if(plist->head == NULL){
        dlnode->pre = NULL;
        dlnode->next = NULL;
        dlnode->data = value;

        plist->head = dlnode;
        plist->tail = dlnode;
        plist->size++;
    }else{
        dlnode->pre = NULL;
        dlnode->next = plist->head;
        dlnode->data = value;

        plist->head->pre = dlnode;
        plist->head = dlnode;
        plist->size++;
    }
}

//添加到链表尾部
void append(DLlist *plist,int value){
    DLNode* dlnode = (DLNode*)malloc(sizeof(DLNode));
    if(plist->head == NULL){
        dlnode->pre = NULL;
        dlnode->next = NULL;
        dlnode->data = value;

        plist->head = dlnode;
        plist->tail = dlnode;
        plist->size++;
    }else{
        dlnode->pre = plist->tail;
        dlnode->next = NULL;
        dlnode->data = value;

        plist->tail->next = dlnode;
        plist->tail = dlnode;
        plist->size++;
    }
}

//删除链表头部
void delHead(DLlist *plist){
    if(plist->head != NULL){
        plist->head = plist->head->next;
        plist->head->pre = NULL;
        plist->size--;
    }
}

//删除链表尾部
void delTail(DLlist *plist){
    if(plist->tail != NULL){
        plist->tail = plist->tail->pre;
        plist->tail->next = NULL;
        plist->size--;
    }
}

void show(DLlist *plist){
    printf("%p-%p-%d\n",plist->head,plist->tail,plist->size);
    DLNode* dlnode = plist->head;
    do{
        printf("%p-%p-%p-%d\n",dlnode,dlnode->pre,dlnode->next,dlnode->data);
        dlnode = dlnode->next;
    }while(dlnode != NULL);
}

int main(){
    DLlist* dllist = (DLlist*)malloc(sizeof(DLlist));
    init(dllist);

    delHead(dllist);
    delTail(dllist);

    add(dllist,2);
    add(dllist,3);
    add(dllist,5);
    delHead(dllist);

    append(dllist,7);
    append(dllist,9);
    delHead(dllist);
    delTail(dllist);

    show(dllist);
    return 1;
}