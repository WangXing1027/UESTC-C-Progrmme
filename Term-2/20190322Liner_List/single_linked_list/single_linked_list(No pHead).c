
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


void list_init(pList* L);                                   //采用头插法初始化链表
bool list_empty(pList L);                                   //判空
void list_length(pList p);                                  //计算链表长度
void list_get(pList p);                                     //获取元素
void list_locate(pList p);                                  //获取元素位置
void list_prior(pList p);                                   //求前驱
void list_next(pList p);                                    //求后继
void list_insert(pList* L);                                 //插入元素
void list_delete(pList* L);                                 //删除元素
void list_clear(pList* L);                     //清空链表
void meun();                                                //选项菜单


int main(){
    pList L = NULL;                                        //定义链表第一个节点
    list_init(&L);
    if(!list_empty(L))    exit(0);            //判空

    meun();
    while(true){
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: list_length(L);     break;
            case 2: list_get(L);    break;
            case 3: list_locate(L);     break;
            case 4: list_prior(L);break;
            case 5: list_next(L);break;
            case 6: list_insert(&L);break;
            case 7: list_delete(&L);break;
            case 8: list_clear(&L);     system("Pause");     return 0;
            default: return 0;    system("Pause");      return 0;
        }
    }
    system("Pause");
    return 0;
}


//采用尾插法初始化链表
void list_init(pList* L){   
    int i,n=10;
    pList p,pre;
    pre = (pList)malloc(sizeof(TNode));
    for(i = 0; i < n; ++i){
        p = (pList)malloc(sizeof(TNode));

        if(!p){
            printf("Wrong!");
            exit(0);
        }
        if(*L == NULL)
            *L = p;
        
        else
            pre->next = p;

        p->next = NULL;
        pre = p;
        p->data.number = i;
    }
}


//判空
bool list_empty(pList L){
    if(L == NULL){
        printf("Empty!\n");
        return false;
    }
    else{
        printf("List has been created.\n");
        return true;
    }
}


//计算链表长度
void list_length(pList p){
    int i = 0;
    while(p){
        p = p->next;
        ++i;
    }
    printf("The length of the list is %d\n\n",i);
    return;
}


//获取元素
void list_get(pList p){
    int i;                    //i表示元素位置
    printf("Enter your location: ");
    scanf("%d", &i);
    for(int j = 1;p != NULL && j < i; ++j)
        p = p->next;
    
    if(!p)
        printf("Doesn't exit!\n\n");

    else
        printf("The item is: %d\n\n",p->data.number);
    
}


//获取元素位置
void list_locate(pList p){
    int i = 1,x;                        //i表示元素位置，x表示元素名称
    printf("Enter your item: ");
    scanf("%d",&x);
    while(p && p->data.number != x){
        p = p->next;
        ++i;
    }
    if(!p)
        printf("Doesn't exit!\n\n");
    else
        printf("The Location of this item is: %d\n\n",i);
}


//求前驱
void list_prior(pList p){
    int i = 1,x;                        //i表示元素位置，x表示元素名称
    printf("Enter your item: ");
    scanf("%d",&x);
    while(p->next && p->next->data.number != x){
        p = p->next;
        ++i;
    }
    if(!p->next)
        printf("Doesn't exit!\n\n");
    else{
        printf("The prior item is: %d.\n",p->data.number);
        printf("The prior location is: %d\n\n",i);
    }
}


//求后继
void list_next(pList p){
    int i = 1,x;                    //i表示元素位置，x表示元素名称
    printf("Enter your item: ");
    scanf("%d",&x);
    while(p->next && p->data.number != x){
        p = p->next;
        ++i;
    }
    if(!p->next)
        printf("Doesn't exit!\n\n");
    else{
        ++i;
        printf("The prior item is: %d.\n",p->next->data.number);
        printf("The prior location is: %d\n\n",i);
    }
}


//插入元素
void list_insert(pList* L){
    int i = 1,x;                //i表示元素位置，x表示元素名称
    pList p = *L;
    printf("Enter the position you want to insert: ");
    scanf("%d",&i);
    printf("Enter the item: ");
    scanf("%d",&x);

    for(int j = 0; p && j < i; ++j)
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
void list_delete(pList* L){
    int i = 1;               //i表示元素位置，x表示元素名称
    pList p = *L;
    printf("Enter the Location you want to delete: ");
    scanf("%d", &i);
    for(int j = 1;p && j < i-1; ++j)
        p = p->next;

    if(!p->next){
        printf("Cannot delete!\n\n");
        return;
    }
    
    if(!p->next->next){       //当删除元素为最后一个元素时
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
void list_clear(pList* L){
    pList p = *L;
    while(p){
        pList pre = p;
        p->next = pre->next;      
        p = p->next;
        free(pre);
        pre = NULL;
    }
}


//选项菜单
void meun(){
    printf("1.length.\n");
    printf("2.get the item\n");
    printf("3.locate the item\n");
    printf("4.get the former item\n");
    printf("5.get the later item\n");
    printf("6.insert a item before\n");
    printf("7.delete a item\n");
    printf("8.clear the list\n");
    printf("default: exit\n");
    printf("======================\n");
}