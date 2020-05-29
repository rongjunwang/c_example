#include <stdio.h>
#include <stdlib.h>

typedef struct bitree{
    char data;
    struct Tree* left;
    struct Tree* right;
} biTree;

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
void levelOrderTree(biTree* tree){
    while(tree){
        tree = tree->left;

    }
}

//深度优先遍历

void main(){
    biTree* tree = create_bitree();
    preOrderTree(tree);
    printf("\n");

    inOrderTree(tree);
    printf("\n");

    nextOrderTree(tree);
    printf("\n");
}