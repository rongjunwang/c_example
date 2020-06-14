#include <stdio.h>
#include <stdlib.h>

//https://www.cnblogs.com/skywang12345/p/3576969.html
typedef int Type;
typedef struct AVLTreeNode{
    Type key;
    int height;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
}Node;

#define MAX(a,b) ( a > b ? a : b)
#define HEIGHT(p) ((p==NULL)?0:(p->height))
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

//创建节点
Node* avltreenode_create(Type key){
    Node* node = malloc(sizeof(Node));
    node->height = 0;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//LL情况，插入点为当前节点left子节点到left中
Node* left_left_rotation(Node* tree){
    Node* new;
    new = tree->left;
    tree->left = new->right;
    new->right = tree;

    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    new->height = MAX(HEIGHT(new->left), HEIGHT(new->right)) + 1;
    return new;
}

//RR情况
Node* right_right_rotation(Node* tree){
    Node* new;
    new = tree->right;
    tree->right = new->left;
    new->left = tree;

    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    new->height = MAX(HEIGHT(new->left), HEIGHT(new->right)) + 1;
    return new;
}

//LR情况
Node* left_right_rotation(Node* tree){
    tree->left = right_right_rotation(tree->left);
    return left_left_rotation(tree);
}

//RL情况
Node* right_left_rotation(Node* tree){
    tree->right = left_left_rotation(tree->right);
    return right_right_rotation(tree);
}

//插入节点
Node* avltreenode_insert(Node* tree, Type key){
    if(tree == NULL){
        tree = avltreenode_create(key);
    }else if(key < tree->key){  //插入到左子树
        tree->left = avltreenode_insert(tree->left, key);

        //printf("left=%d;right=%d\n",HEIGHT(tree->left),HEIGHT(tree->right) );
        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2){
            if(key < tree->left->key){
                tree = left_left_rotation(tree);
            }else{
                tree = left_right_rotation(tree);
            }
        }

    }else if(key > tree->key){  //插入到右子树
        tree->right = avltreenode_insert(tree->right, key);
        
        //printf("left=%d;right=%d\n",HEIGHT(tree->left),HEIGHT(tree->right) );
        if(HEIGHT(tree->right) - HEIGHT(tree->left) == 2){
            if(key > tree->right->key){
                tree = right_right_rotation(tree);
            }else{
                tree = right_left_rotation(tree);
            }
        }
    }

    tree->height = MAX(HEIGHT(tree->left),HEIGHT(tree->right)) + 1;

    return tree;
}

//找最大节点
Node* avltree_max(Node* tree){
    if(tree == NULL) return NULL;
    while(tree->right != NULL) tree = tree->right;
    return tree;
}

//找最小节点
Node* avltree_min(Node* tree){
    if(tree == NULL) return NULL;
    while(tree->left != NULL) tree = tree->left;
    return tree;
}

//删除节点
Node* avltreenode_delete(Node* tree, Node* node){
    if(tree == NULL || node == NULL){
        return NULL;
    }

    if(node->key < tree->key){      //node在左子树
        tree->left = avltreenode_delete(tree->left, node);

        if( HEIGHT(tree->right) - HEIGHT(tree->left) == 2){
            Node* r = tree->right;
            if( HEIGHT(r->left) > HEIGHT(r->right)){
                tree = right_left_rotation(tree);
            }else{
                tree = right_right_rotation(tree);
            }
        }
    }else if(node->key > tree->key){
        tree->right = avltreenode_delete(tree->right, node);

        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2){
            Node* l = tree->left;
            if( HEIGHT(l->left) < HEIGHT(l->right) ){
                tree = left_right_rotation(tree);
            }else{
                tree = left_left_rotation(tree);
            }
        }
    }else{                          //相等情况，删除节点
        if(tree->left != NULL && tree->right != NULL){
            if( HEIGHT(tree->left) > HEIGHT(tree->right) ){
                Node* max = avltree_max(tree->left);
                tree->key = max->key;
                tree->left = avltreenode_delete(tree->left, max);
            }else{
                Node* min = avltree_min(tree->right);
                tree->key = min->key;
                tree->right = avltreenode_delete(tree->right, min);
            }
        }else{
            Node* temp = tree;
            tree = tree->left ? tree->left : tree->right;
            free(temp);
        }
    }

    return tree;
}

//前序打印
void avltree_printf(Node* tree, int deep){
    if(tree){
        printf("deep=%d;key=%d;height=%d\n", deep, tree->key, tree->height);
        avltree_printf(tree->left, deep+1);
        avltree_printf(tree->right, deep+1);
    }
}

int vec_left[100] = {0};
void Display(Node* root, int ident)
{
    if(ident > 0)
    {
        for(int i = 0; i < ident - 1; ++i)
        {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident-1] ? "├── " : "└── ");
    }

    if(! root)
    {
        printf("(null)\n");
        return;
    }

    printf("%d\n", root->key);
    if(!root->left && !root->right)
    {
        return;
    }

    vec_left[ident] = 1;
    Display(root->left, ident + 1);
    vec_left[ident] = 0;
    Display(root->right, ident + 1);
}

void main(){
    Node* tree = NULL;
    int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9,20,21,22,23,24,25,26,27};
    for(int i=0;i<TBL_SIZE(arr);i++){
        tree = avltreenode_insert(tree, arr[i]);
    }
    avltree_printf(tree, 0);
    Display(tree, 0);

    printf("\n");
    Node* delNode = NULL;
    delNode = avltreenode_create(20);
    tree = avltreenode_delete(tree, delNode);
    Display(tree, 0);
}