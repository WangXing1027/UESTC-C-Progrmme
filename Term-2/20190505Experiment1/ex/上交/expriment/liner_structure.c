#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxSize 100

typedef int ElemType;

typedef struct{
    ElemType* data;     //数据域
    int length;         //目前长度
    int capacity;       //最大存储量
}TList,*pList;

void list_init(pList* L,int num){
    pList p;

    //为p分配内存
    p = (pList)malloc(sizeof(TList));

    if(!p){
        printf("Wrong!");
        exit(0);
    }
    p->length = 0;
    p->capacity = maxSize;

    //为data域分配内存
    int nSize = sizeof(ElemType) * num;
    p->data = (ElemType*)malloc(nSize);
    if(!(p->data)){
        printf("Wrong!");
        free(p);
        exit(0);
    }

    //填充数据
    for(int i = 0; i < nSize; ++i)
        p->data[i] = i + num;
    *L = p; //返回
}

void list_destroy(pList *L){
    pList p = *L;
    if(p)
    {
        if(p->data)
           free(p->data);
    }
    p = NULL;
}

void list_union(pList *La,pList *Lb){

}


int main()
{
    pList La,Lb;
    int num1,num2;
    num1 = 50;num2 = 100;

    list_init(&La,num1);
    list_init(&Lb,num2);

    for(int i = 0;i < 100; ++i)
        printf("La:%d,Lb:%d/t",La->data[i],Lb->data[i]);

    list_destroy(&La);

    return 0;
}