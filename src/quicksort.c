#include <stdio.h>
#include <unistd.h>
#define MAX_SIZE 10
void swap(int* a,int* b);
void show(int array[],int len);
void QuickSort(int* array, int startPos, int endPos,int len){
    int key = array[startPos];
    int i = startPos;
    int j = endPos;
    while(i < j){
        while(array[j] >= key && i<j) j--;
        if(i<j) array[i] = array[j];

        while(array[i] <= key && i<j) i++;
        if(i<j) array[j] = array[i];
       
        show(array,len);
    }

    array[i] = key; 
    printf("%d-%d\n",i,key);
    if(i-1>startPos) QuickSort(array, startPos, i-1,len);
    if(endPos>i+1) QuickSort(array, i+1, endPos,len);
}

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void show(int* array, int len){
    for(int i=0;i<len;i++){
        printf("%d,",array[i]);
    }
    printf("\n");
}

void main(){
    int array[MAX_SIZE] = {0,6,7,8,12,1,3,4,65,4};
    int len = sizeof(array)/sizeof(int);
    printf("len=%d\n",len);
    printf("排序之前的数组\n");
    show(array,len);
    printf("\n");

    QuickSort(array,0,len-1,len);
    
    printf("\n");
    printf("排序之后的数组\n");
    show(array,len);
}