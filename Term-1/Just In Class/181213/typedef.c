#include<stdio.h>

typedef int value_type;

typedef struct _node
{
    value_type data;
    struct _node *next;
}node;

typedef node* nodeptr;

int main()
{
    node a = {1}, b = {2} , c = {3};

    nodeptr p;

    a.next = &b;
    b.next = &c;

    p = &a;

    while(p != NULL)
    {
        printf("%5d", p->data);
        p = p->next;
    }

	   
    return 0;
}

GoodsList* info_init(void){                                     
	if(check_nullfile()==0){
	    int i;
    for(;;){
    	printf("请输入商品信息");
    	scanf("%d",&i);
    	if(i==1||i==0)
    	break;
    }
    if(i==1){
    	GoodsList *new_node=malloc(sizeof(GoodsList));
    	printf("输入你要插入的商品信息:\n");
		printf("商品ID: ");
		scanf("%s",new_node->data.goods_id);
		printf("商品名称: ");
		scanf("%s",new_node->data.goods_name);
		printf("商品价格: ");
		scanf("%d",&new_node->data.goods_price);
		printf("商品折扣: ");
		scanf("%s",new_node->data.goods_discount);
		printf("商品数量: ");
		scanf("%d",&new_node->data.goods_amount);
		printf("商品剩余: ");
		scanf("%d",&new_node->data.goods_remain);
 		CurrentCnt++;
 		printf("商品%s已经录入，现在有1个商品记录\n",new_node->data.goods_name);
		 smooth(); 
 		return new_node;
    }
	else
	exit(0);
	}
	CurrentCnt++;
	
	GoodsList *new_good=malloc(sizeof(struct node));
	GoodsList *head=NULL;
	new_good->next=NULL;
	FILE *fp=fopen("goodsinfo.txt", "r");
	fscanf(fp,"%s%s%d%s%d%d",&((new_good->data).goods_id),&((new_good->data).goods_name),
    &((new_good->data).goods_price),&((new_good->data).goods_discount),
	&((new_good->data).goods_amount),&((new_good->data).goods_remain));
	head=new_good;
	
	while (!feof(fp)){
		
		new_good=malloc(sizeof(struct node));
		new_good->next=head;
		fscanf(fp,"%s%s%d%s%d%d",&((new_good->data).goods_id),&((new_good->data).goods_name),
    	&((new_good->data).goods_price),&((new_good->data).goods_discount),
		&((new_good->data).goods_amount),&((new_good->data).goods_remain));
		head=new_good;	
		CurrentCnt++;
	}
	fclose(fp);
	return head;
	
		
}

