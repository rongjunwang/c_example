redis
============

数据类型
------------
string 
list
hash 
set
sort set

数据结构
------------
#### SSD(simple dynamic string)
 ```
 struct sdshdr{
    //记录buf数组中已经使用的字节的数量
    //等于SDS所保存字符串的长度
    int len;

    //记录buf数组中未使用字节的数量
    int free;

    //字节数组，用户保存字符串
    char buf[];
 }
 ```
 知识点:
 * 记录长度，不同于c语言的字符串。计算长度时间复杂度O(1) 和 杜绝内存溢出，保证字符串的二进制安全
 * 动态增加内存，减少字符串内存重分配次数。<1MB，每次翻倍增加+1byte，>1MB，每次增加1MB+1byte。（1byte是'\0'）
 * 兼容c语言的字符串函数

 #### 链表
 ```
 typedef struct listNode{
     //前置节点
     struct listNode *prev;

     //后置节点
     struct listNode *next;

     //节点的值
     void *value;
 }

 typedef struct list { 
     //表头节点 
     listNode * head;

     //表尾节点 
     listNode * tail; 

     //链表所包含的节点数量 
     unsigned long len; 

     //节点值复制函数 
     void *(*dup)( void *ptr); 

     //节点值释放函数 
     void (*free)( void *ptr); 

     //节点值对比函数 
     int (*match)( void *ptr, void *key); 
} list;

 ```
 * 知识点
    * 链表被广泛用于实现Redis的各种功能，比如列表键、发布与订阅、慢查询、监视器等。 
    * 每个链表节点由一个listNode结构来表示，每个节点都有一个指向前置节点和后置节点的指针，所以Redis的链表实现是双端链表。 
    * 每个链表使用一个list结构来表示，这个结构带有表头节点指针、表尾节点指针，以及链表长度等信息。 
    * 因为链表表头节点的前置节点和表尾节点的后置节点都指向 NULL，所以Redis的链表实现是无环链表。
    * 通过为链表设置不同的类型特定函数，Redis的链表可以用于保存各种不同类型的值。

#### 


