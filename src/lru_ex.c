#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct doublyLinkList{
    int key;
    struct doublyLinkList* pre;
    struct doublyLinkList* next;
    int value;
} DLNode;

typedef struct {
    int key;
    DLNode* node;
    DLNode* next;
} hashTable;

typedef struct {
    int capacity;
    int used;

    //双端链表
    DLNode* head;
    DLNode* tail;

    //hashtable
    hashTable* hashtable[MAX_SIZE];
} LRUCache;

//time33算法
unsigned int time33(int key){
    int hash = 5381;
    while(key){
        hash += (hash << 5) + key--;
    }
    return (hash & 0x7FFFFFFF) % MAX_SIZE;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = malloc(sizeof(LRUCache));
    cache->head = NULL;
    cache->tail = NULL;
    cache->used = 0;
    for(int i=0;i<MAX_SIZE;i++){
        cache->hashtable[i] = NULL;
    }
    cache->capacity = capacity;
    return cache;
}

void LRUCacheClean(LRUCache* obj){
    //使用空间大于预设大小，触发清除
    if(obj->used > obj->capacity){
        //1.清除双端链表节点
        int keyClean = obj->tail->key;
        obj->tail->pre->next = NULL;
        obj->tail = obj->tail->pre; 

        //2.清空hashtable里面的数据
        unsigned int hash = time33(keyClean);
        hashTable* table = obj->hashtable[hash];
        hashTable* temp = NULL;
        while(table != NULL){
            if(table->key == keyClean){
                if(temp != NULL) temp->next = table->next;
                else obj->hashtable[hash] = table->next;
            }
            //记录上一次的节点
            temp = table;
            table = table->next;
        }
        obj->used--;
    }
}

//改变节点放在首部
void lRUCacheChangeFirst(LRUCache* obj, DLNode* node){
    if(node->pre == NULL) return;
    node->pre->next = node->next;
    if(node->next) node->next->pre = node->pre;
    else obj->tail = node->pre;
    node->pre = NULL;
    node->next = obj->head;
    obj->head->pre = node;
    obj->head = node;
}

int LRUCacheGetKey(hashTable* table, int key){
    while(table){
        if(table->key == key) return 1;
        table = table->next;
    }
    return 0;
}

int lRUCacheGet(LRUCache* obj, int key) {
    unsigned int hash = time33(key);
    hashTable *table = malloc(sizeof(hashTable));
    table = obj->hashtable[hash];
    while(table){
        if(table->key == key){
            lRUCacheChangeFirst(obj, table->node);
            return table->node->value;
        };
        table = table->next;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    
    unsigned int hash = time33(key);
    hashTable *table = malloc(sizeof(hashTable));
    table = obj->hashtable[hash];

    //寻找hash
    while(table){
        if(table->key == key){
            lRUCacheChangeFirst(obj, table->node);
            table->node->value = value;
            return;
        };
        table = table->next;
    }

    //插入节点到双端链表
    DLNode* dlnode = malloc(sizeof( DLNode ));
    dlnode->pre = NULL;
    dlnode->next = obj->head == NULL ? NULL : obj->head;
    dlnode->key = key;
    dlnode->value = value;
    if(obj->head != NULL){
        obj->head->pre = dlnode;
        obj->head = dlnode; 
    }else{
        obj->head = dlnode;
        obj->tail = dlnode;
    }

    //hashtable更新
    hashTable *newTable = malloc(sizeof(hashTable));
    newTable->key = key;
    newTable->node = dlnode;
    newTable->next = obj->hashtable[hash];
    obj->hashtable[hash] = newTable; 

    //添加次数
    obj->used++;

    //超过预设值，清除
    LRUCacheClean(obj);
}

void lRUCacheFree(LRUCache* obj) {

}

void show(LRUCache *obj){
    printf("capacity=%d\n",obj->capacity);
    printf("used=%d\n",obj->used);

    DLNode *node = obj->head;
    printf("head=%p;tail=%p\n", obj->head, obj->tail);
    while(node != NULL){
        printf("%d;%d;%p;%p;%p\n",node->key,node->value,node,node->pre,node->next);
        node = node->next;
    }
    printf("\n");

    for (int i = 0; i < MAX_SIZE; i++)
    {
        hashTable* table = obj->hashtable[i];
        if(table != NULL){
            while(table){
                printf("%d;%d;%p;%p;%p\n",i,table->key,table,table->next,table->node);
                table = table->next;
            }
        }
    }
    printf("\n");
}

int main(){
    LRUCache* pcache = lRUCacheCreate(2);
    printf("%d\n",lRUCacheGet(pcache, 1));
    lRUCachePut(pcache, 1, 1);
    lRUCachePut(pcache, 2, 2);

    show(pcache);
    
    printf("%d\n",lRUCacheGet(pcache, 1));
    show(pcache);

    lRUCachePut(pcache, 3, 3);
    printf("%d\n",lRUCacheGet(pcache, 2));
    show(pcache);
    lRUCachePut(pcache, 4, 4);

    printf("%d\n",lRUCacheGet(pcache, 1));
    printf("%d\n",lRUCacheGet(pcache, 3));
    printf("%d\n",lRUCacheGet(pcache, 4));

    return 1;
}