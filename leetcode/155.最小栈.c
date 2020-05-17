/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 */

// @lc code=start

#define MAX_SIZE 10000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Stack* top;
    Stack* helpTop;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    Stack* stack1 = (Stack*)malloc(sizeof(Stack));
    stack1->top = 0;
    minStack->top = stack1;

    Stack* stack2 = (Stack*)malloc(sizeof(Stack));
    stack2->top = 0;
    minStack->helpTop = stack2;

    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    obj->top->data[obj->top->top++] = x;

    if(obj->helpTop->top == 0){
         obj->helpTop->data[obj->helpTop->top++] = x;
    }else{
        if(obj->helpTop->data[obj->helpTop->top - 1] >= x){
            obj->helpTop->data[obj->helpTop->top++] = x;
        }
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top->top > 0){
         int value = obj->top->data[obj->top->top - 1];
        obj->top->top--;

        if(obj->helpTop->data[obj->helpTop->top - 1] == value){
            obj->helpTop->top--;
        }
    }
}

int minStackTop(MinStack* obj) {
    return  obj->top->top > 0? obj->top->data[obj->top->top - 1] : NULL;
}

int minStackGetMin(MinStack* obj) {
   return obj->helpTop->top > 0 ? obj->helpTop->data[obj->helpTop->top - 1] : NULL;
}

void minStackFree(MinStack* obj) {
    free(obj->helpTop);
    free(obj->top);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end

