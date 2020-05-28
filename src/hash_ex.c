#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2
struct table
{
    char *key;
    char *value;
    struct table* next;
} tb;
typedef struct 
{
    struct table** table;
} hashTable;

//time33-hash算法
unsigned int time33(char* key){
    unsigned int hash = 5381;
    while(*key){
        hash += (hash<<5) + (*key++);
    }
    return (hash & 0x7FFFFFFF);
}

hashTable* create(){
    hashTable* ht = malloc(sizeof(hashTable));
    ht->table = malloc(sizeof(struct table) * (MAX_SIZE));
    return ht;
}

int add(hashTable* ht,char* key, char* value){
    unsigned int hash = time33(key);
    hash = hash%MAX_SIZE;
    struct table* tb = malloc(sizeof(struct table));
    tb->next = NULL;
    tb->key = key;
    tb->value = value;

    if(ht->table[hash] != NULL){
        struct table* pre = ht->table[hash];
        while(pre->next != NULL){pre = pre->next;}
        pre->next = tb;
    }else{
        ht->table[hash] = tb;
    }
    return 1;
}

char* get(hashTable* ht, char* key){
    unsigned int hash = time33(key);
    hash = hash%MAX_SIZE;
    struct table* tb = ht->table[hash];
    while(tb != NULL){
        if(tb->key == key){
            return tb->value;
        }
        tb = tb->next;
    }
   return NULL;
}

void main(){
    hashTable* ht = create();
    
    char *key = "key";
    char *value = "value";
    add(ht, key, value);

    char *key1 = "key-1";
    char *value1 = "value-1";
    add(ht, key1, value1);
    
    char *key2 = "key-2";
    char *value2 = "value-2";
    add(ht, key2, value2);

    char *key3 = "key-3";
    char *value3 = "value-3";
    add(ht, key3, value3);

    char *key4 = "key-4";
    char *value4 = "value-4";
    add(ht, key4, value4);

    char *key5 = "key-5";
    char *value5 = "value-5";
    add(ht, key5, value5);

    char *res = get(ht, key);
    char *res1 = get(ht, key1);
    char *res2 = get(ht, key2);
    char *res3 = get(ht, key3);
    char *res4 = get(ht, key4);
    char *res5 = get(ht, key5);
    printf("res=%s\n",res);
    printf("res1=%s\n",res1);
    printf("res2=%s\n",res2);
    printf("res3=%s\n",res3);
    printf("res4=%s\n",res4);
    printf("res5=%s\n",res5);
    printf("\n");


    for(int i=0;i<MAX_SIZE;i++){
        struct table* tb = ht->table[i];
        printf("i=%d-%s\n",i,tb->value);

        while(tb != NULL){
            printf("%s-",tb->value);
            tb = tb->next;
        }
        printf("\n");
    }
}