#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int number;
}ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
}TNode,*pList;


void list_init(pList* pHead,pList* pTail);                  //采用头插法初始化链表
bool list_empty(pList pHead,pList pTail);                   //判空
void list_insert(pList* pHead);                             //插入元素
void list_delete(pList* pHead);                             //删除元素
void list_clear(pList* pHead,pList* pTail);                  //清空链表
void meun();                                                 //选项菜单


int main(){
    pList pHead = NULL;                                 //定义链表头节点
    pList pTail = pHead;                                //定义列表尾节点
    list_init(&pHead,&pTail);
    if(!list_empty(pHead,pTail))    exit(0);            //判空

    meun();
    while(true){
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: list_insert(&pHead);break;
            case 2: list_delete(&pHead);break;
            case 3: list_clear(&pHead, &pTail);     system("Pause");     return 0;
            default: return 0;    system("Pause");      return 0;
        }
    }
    system("Pause");
    return 0;
}


//采用头插法初始化链表
void list_init(pList* pHead,pList* pTail){   
    int i,n=10;
    pList p = *pHead;
    *pHead = *pTail = (pList)malloc(sizeof(TNode));
    for(i = 0; i < n; ++i){
        p = (pList)malloc(sizeof(TNode));
        if(!(p)){
            printf("Wrong!");
            exit(0);
        }
        p->data.number = i;         //该节点的数据域
        p->next = NULL;             //尾指针next域为空
        (*pTail)->next = p;         //用尾插法插入p节点
        *pTail = p;                 //更改尾指针指向节点
    }
    (*pTail)->next = *pHead;
}


//判空
bool list_empty(pList pHead,pList pTail){
    if(pHead == pTail){
        printf("Empty!\n");
        return false;
    }
    else{
        printf("List has been created.\n");
        return true;
    }
}


//插入元素
void list_insert(pList* pHead){
    int i = 1,x;                //i表示元素位置，x表示元素名称
    pList p = (*pHead)->next;
    printf("Enter the position you want to insert: ");
    scanf("%d",&i);
    printf("Enter the item: ");
    scanf("%d",&x);

    for(int j = 0; p->next != *pHead && j < i; ++j)
        p = p->next;
    
    if(!p){
        printf("Cannot Insert!\n\n");
        return;
    }

    pList pre;
    pre = (pList)malloc(sizeof(TNode));
    pre->data.number = x;
    pre->next = p->next;
    p->next = pre;

    printf("Successfully Insert!\n\n");
}


//删除元素
void list_delete(pList* pHead){
    int i = 1;               //i表示元素位置，x表示元素名称
    pList p = (*pHead)->next;
    printf("Enter the Location you want to delete: ");
    scanf("%d", &i);
    for(int j = 1;p->next != *pHead && j < i-1; ++j)
        p = p->next;

    if(p->next == *pHead){
        printf("Cannot delete!\n\n");
        return;
    }
    
    if(p->next->next == *pHead){       //当删除元素为最后一个元素时
        pList pre = p->next;
        free(pre);
        p->next = NULL;
    }
    
    else
    {
        pList pre = p->next;
        p->next = pre->next;
        free(pre);
    }
    printf("Successfully Delete!\n\n");
    
}

//清空链表
void list_clear(pList* pHead,pList* pTail){
    pList p = *pHead;
    while(p->next != *pHead){
        pList pre = p;
        p->next = pre->next;      
        p = p->next;
        free(pre);
        pre = NULL;
    }
    *pTail = *pHead = NULL;
}


//选项菜单
void meun(){
    printf("1.insert a item before\n");
    printf("2.delete a item\n");
    printf("3.clear the list\n");
    printf("default: exit\n");
    printf("======================\n");
}
