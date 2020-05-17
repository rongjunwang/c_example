/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU缓存机制
 */

// @lc code=start

typedef struct DoublyLinkListNode{
    int key;
    struct DoublyLinkListNode* pre;
    struct DoublyLinkListNode* next;
    int value;
}DLNode;

typedef struct LastRUCache{
    int capacity;
    DLNode* head;
    DLNode* tail;

    int used;
    DLNode* hash[10];
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = (DLNode*)malloc(sizeof(DLNode));
    cache->head = NULL;
    cache->tail = (DLNode*)malloc(sizeof(DLNode));
    cache->tail = NULL;
    cache->used = 0;
    for(int i=0;i<10;i++){
        cache->hash[i] = (DLNode*)malloc(sizeof(DLNode));
        cache->hash[i] = NULL;
    }
    cache->capacity = capacity;
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(obj->hash[key] != NULL){
        if(obj->hash[key]->pre != NULL){
            if(obj->hash[key]->next == NULL){
                obj->tail = obj->hash[key]->pre;
                obj->tail->next = NULL;
            }
            obj->hash[key]->pre->next = obj->hash[key]->next;
            obj->hash[key]->next->pre = obj->hash[key]->pre; 

            obj->head->pre = obj->hash[key];
            obj->hash[key]->next = obj->head;
            obj->hash[key]->pre = NULL;
            obj->head = obj->hash[key];
        }
        printf("get\n");
        show(obj);
        return obj->hash[key]->value;
    }

    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {

    //如果存在，放在首部
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
        obj->hash[key]->value = value;
    }
    else
    {
        if(obj->head == NULL){
            DLNode* dlnode = (DLNode*)malloc(sizeof( DLNode ));
            dlnode->next = NULL;
            dlnode->pre = NULL;
            dlnode->value = value;
            dlnode->key = key;

            obj->head= dlnode;
            obj->tail = dlnode;
            
            obj->hash[key] = dlnode;
            obj->used++;
        }else{
            DLNode* dlnode = (DLNode*)malloc(sizeof( DLNode ));
            dlnode->next = obj->head;
            dlnode->pre = NULL;
            dlnode->value = value;
            dlnode->key = key;

            obj->head->pre = dlnode;
            obj->head = dlnode;

            obj->hash[key] = dlnode;
            obj->used++;
        }

        if(obj->used > obj->capacity){
            if(obj->tail->key != NULL){
                int overdutKey = obj->tail->key;
                obj->tail->pre->next = NULL;
                obj->tail = obj->tail->pre;
                obj->used--;

                obj->hash[overdutKey] = NULL;
            }
        }
    }
    

    
    show(obj);
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
}

void show(LRUCache *obj){
    
    printf("%p-%p-%d-%d\n",obj->head,obj->tail,obj->capacity,obj->used);
    DLNode* dlnode = obj->head;
    while(dlnode !=  NULL){
        printf("%p-%p-%p-%d-%d\n",dlnode,dlnode->pre,dlnode->next,dlnode->key,dlnode->value);
        dlnode = dlnode->next;
    }
    printf("\n");
        
}


/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// @lc code=end

