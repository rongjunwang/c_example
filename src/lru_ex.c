#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkListNode{
    int key;
    struct DoublyLinkListNode* pre;
    struct DoublyLinkListNode* next;
    int value;
} DLNode;

typedef struct LastRUCache{
    int capacity;
    struct DoublyLinkListNode* head;
    struct DoublyLinkListNode* tail;

    int used;
    struct DoublyLinkListNode* hash[10];
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = NULL;
    cache->tail = NULL;
    cache->used = 0;
    for(int i=0;i<10;i++){
        cache->hash[i] = NULL;
    }
    cache->capacity = capacity;
    return cache;
}

void lRUCacheGet(LRUCache* obj, int key) {
    if(obj->hash[key] != NULL){
        if(obj->hash[key]->pre != NULL){
            if(obj->hash[key]->next == NULL){
                obj->tail = obj->hash[key]->pre;
                obj->tail->next = NULL;
            }
            obj->head->pre = obj->hash[key];
            obj->hash[key]->next = obj->head;
            obj->hash[key]->pre = NULL;
            obj->head = obj->hash[key];
        }
        printf("%d\n",obj->hash[key]->value);
        return;
    }

    printf("-1\n");
    
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->used == obj->capacity){
        int overdutKey = obj->tail->key;
        obj->tail->pre->next = NULL;
        obj->tail = obj->tail->pre;
        obj->used--;

        obj->hash[overdutKey] = NULL;
    }

    if(obj->head == NULL){
        DLNode* dlnode = (DLNode*)malloc(sizeof(DLNode));
        dlnode->next = NULL;
        dlnode->pre = NULL;
        dlnode->value = value;
        dlnode->key = key;

        obj->head= dlnode;
        obj->tail = dlnode;
        
        obj->hash[key] = dlnode;
        obj->used++;
    }else{
        DLNode* dlnode = (DLNode*)malloc(sizeof(DLNode));
        dlnode->next = obj->head;
        dlnode->pre = NULL;
        dlnode->value = value;
        dlnode->key = key;

        obj->head->pre = dlnode;
        obj->head = dlnode;

        obj->hash[key] = dlnode;
        obj->used++;
    }
}

void lRUCacheFree(LRUCache* obj) {

}

void show(LRUCache *obj){
    DLNode* dlnode = obj->head;
    printf("%p-%p-%d-%d\n",obj->head,obj->tail,obj->capacity,obj->used);
    while(dlnode !=  NULL){
        printf("%p-%p-%p-%d-%d\n",dlnode,dlnode->pre,dlnode->next,dlnode->key,dlnode->value);
        dlnode = dlnode->next;
    }
        
}

int main(){
    LRUCache* pcache = lRUCacheCreate(2);
    lRUCacheGet(pcache, 1);
    lRUCachePut(pcache, 1, 1);
    lRUCachePut(pcache, 2, 2);
    lRUCacheGet(pcache, 1);
    lRUCachePut(pcache, 3, 3);
    lRUCacheGet(pcache, 2);
    lRUCachePut(pcache, 4, 4);

    lRUCacheGet(pcache, 1);
    lRUCacheGet(pcache, 3);
    lRUCacheGet(pcache, 4);

    return 1;
}