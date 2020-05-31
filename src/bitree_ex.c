#include <stdio.h>
#include <stdlib.h>

typedef struct bitree{
    char data;
    struct Tree* left;
    struct Tree* right;
} biTree;

//树读遍历方式：
//广度遍历包含-前序遍历，中序遍历，后序遍历
//深度遍历包含-层遍历

biTree* create_bitree(){
    char data;
    biTree* tree; 

    scanf("%c",&data);
    if(data != '#'){
        tree = malloc(sizeof(biTree));
        tree->data = data;
        tree->left = create_bitree();
        tree->right = create_bitree();
    }else{
        tree = NULL;
    }
    return tree;
}

//前序遍历（根结点 ---> 左子树 ---> 右子树）
void preOrderTree(biTree* tree){
    if(tree){
        printf("%c ",tree->data);
        preOrderTree(tree->left);
        preOrderTree(tree->right);
    }
}

//中序遍历（左子树 ---> 根结点 ---> 右子树）
void inOrderTree(biTree* tree){
    if(tree){
        inOrderTree(tree->left);
        printf("%c ",tree->data);
        inOrderTree(tree->right);
    }
}

//后序遍历（左子树 ---> 右子树 ---> 根结点）
void nextOrderTree(biTree* tree){
    if(tree){
        nextOrderTree(tree->left);
        nextOrderTree(tree->right);
        printf("%c ",tree->data);
    }
}

//层遍历
void levelOrderTree(biTree* tree, int level,int* j,char** res){
   if(tree){
       if(!res[level]){
           res[level] = calloc(10,sizeof(char));
           j[level] = 0;
        } 
        res[level][j[level]++] = tree->data;
        printf("%d;%d;%c\n",level,j,tree->data);
        levelOrderTree(tree->left,level+1,j,res);
        levelOrderTree(tree->right,level+1,j,res);
    }
}

void main(){
    biTree* tree = create_bitree();
    preOrderTree(tree);
    printf("\n");

    inOrderTree(tree);
    printf("\n");

    nextOrderTree(tree);
    printf("\n");

    char** res = calloc(100,sizeof(char*));
    int* j = calloc(100,sizeof(int));
    levelOrderTree(tree,0,j,res);
    printf("%s-%s-%s\n",res[0],res[1],res[2]);
}