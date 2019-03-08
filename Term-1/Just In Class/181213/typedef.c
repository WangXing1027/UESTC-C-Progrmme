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
    	printf("��������Ʒ��Ϣ");
    	scanf("%d",&i);
    	if(i==1||i==0)
    	break;
    }
    if(i==1){
    	GoodsList *new_node=malloc(sizeof(GoodsList));
    	printf("������Ҫ�������Ʒ��Ϣ:\n");
		printf("��ƷID: ");
		scanf("%s",new_node->data.goods_id);
		printf("��Ʒ����: ");
		scanf("%s",new_node->data.goods_name);
		printf("��Ʒ�۸�: ");
		scanf("%d",&new_node->data.goods_price);
		printf("��Ʒ�ۿ�: ");
		scanf("%s",new_node->data.goods_discount);
		printf("��Ʒ����: ");
		scanf("%d",&new_node->data.goods_amount);
		printf("��Ʒʣ��: ");
		scanf("%d",&new_node->data.goods_remain);
 		CurrentCnt++;
 		printf("��Ʒ%s�Ѿ�¼�룬������1����Ʒ��¼\n",new_node->data.goods_name);
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

