#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100								//商品的最大数量
int CurrentCnt = 0;						//全局变量，存储当前商品的数量

//商品信息结构的定义
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct {
	char	GoodsInfos_id[MAX_ID_LEN];
	char	GoodsInfos_name[MAX_NAME_LEN];
	int  	GoodsInfos_price;
	char	GoodsInfos_discount[MAX_DISCOUNT_LEN];
	int		GoodsInfos_amount;
	int		GoodsInfos_remain;
} GoodsInfo;

typedef struct node{
	GoodsInfo data;
	struct node *next;
}GoodsList;

bool check_nullfile(void);						//检查商品文件是否存在或者是否为空
void info_init(GoodsList **head);				//读取商品文件GoodsInfo.txt的内容,并建立链表L

int read_line(char str[], int n);				//以行读取输入的信息
void menu();									//主菜单栏
void NoGoodsStored(GoodsList **head);			//当没有商品信息时,提醒用户录入数据
bool check_decision(void);						//询问用户是否确定其选择

GoodsList* GoodsInfoChange(GoodsList *p);		//读取更改后新的信息
void GoodsInfoPrint(GoodsList *p);				//打印单个商品链表节点的信息
bool GoodsInfoSearch(GoodsList **p);			//寻找单个商品的位置及信息
void GoodsInfoDestroy(GoodsList **L);			//删除所有商品的链表

void info_output_all(GoodsList *L);				//1.显示所有商品的信息
void info_search(GoodsList *L);					//2.查找一条商品记录
void info_change(GoodsList **L);				//3.修改一条商品记录
void info_insert(GoodsList **L);				//4.添加一条商品记录
void info_bubble_sort(GoodsList **L);			//5.对商品价格进行排序
void info_dele(GoodsList **L);					//6.删除一条商品记录
void info_del_all(GoodsList **L);				//7.删除商品文件及信息
void info_flush(GoodsList **L);					//8.保存内容并退出


//主函数
int main()
{
	GoodsList *L = NULL;

	char choice;
	info_init(&L);					//读取商品文件并建立链表

	NoGoodsStored(&L);				//当没有数据时提醒用户输入数据

	while (1)
	{
		menu();

		scanf(" %c", &choice);
		while (getchar() != '\n')   /* skips to end of line */
			;

		switch (choice)
		{
		case '1':					//1.显示所有商品的信息
			info_output_all(L);
			break;
		case '2':					//2.查找某个商品的信息
			info_search(L);
			break;
		case '3':					//3.修改某个商品的信息
			info_change(&L);
			break;
		case '4':					//4.插入某个商品的信息
			info_insert(&L);
			break;
		case '5':					//5.对商品价格进行排序
			info_bubble_sort(&L);
			break;
		case '6':					//6.删除某个商品的信息
			info_dele(&L);
			break;
		case '7':					//7.（慎用）删除所有内容
			info_del_all(&L);
			return 0;
		case '8':					//8.商品存盘并退出系统
			info_flush(&L);
			return 0;
		default:					//其他
			return 0;
		}

		puts("\n");
		system("Pause");
		system("cls");
	}

	return 0;
}


//检查商品文件是否存在或者是否为空
bool check_nullfile(void)
{
	FILE *fp = fopen("GoodsInfo.txt", "r");

	if (!fp)		//文件不存在
	{
		printf("The product information initialization file doesn't exist!!\n");
		printf("The program will create a new one for you.\n\n");

		FILE *fp = fopen("GoodsInfo.txt", "w");
		fclose(fp);

		return false;
	}
	else				//文件存在
	{
		int temp;		//判断文件是否为空
		int res = fscanf(fp, "%d", &temp);
		fclose(fp);
		if (res <= 0)
			return false;
		else
			return true;
	}
}


//读取商品文件GoodsInfo.txt的内容,并建立链表L
void info_init(GoodsList **head)
{
	GoodsList *pre, *p;
	pre = (GoodsList *)malloc(sizeof(GoodsList));

	if (check_nullfile())							//判断文件是否存在，存在且不为空则返回1
	{
		FILE *fp = fopen("GoodsInfo.txt", "r");

		while (!feof(fp))
		{

			p = (GoodsList *)malloc(sizeof(GoodsList));

			if (*head == NULL)		//头节点
				*head = p;

			else					//后续结构
				pre->next = p;

			p->next = NULL;
			pre = p;
			fscanf(fp, "%s%s%d%s%d%d\t", (p->data).GoodsInfos_id, (p->data).GoodsInfos_name, &(p->data).GoodsInfos_price,
									 &(p->data).GoodsInfos_discount, &(p->data).GoodsInfos_amount, &(p->data).GoodsInfos_remain);
			++CurrentCnt;

			if (CurrentCnt > MAX)
			{
				printf("Too Many Commedies!Cannot load!");		//商品信息过多
				exit(-1);
			}
		}

		fclose(fp);
	}
	
	printf("The list of items has been created. %d commodities have been recorded.\n\n", CurrentCnt);
}


//当没有商品信息时,提醒用户录入数据
void NoGoodsStored(GoodsList **head)
{
	if (*head == NULL)
	{
		printf("Sorry, No Good Stored! Whether to insert one? (y/n): ");

		if (check_decision())				//确认用户是否选择插入商品信息
		{
			GoodsList *L;
			L = *head;
			L = (GoodsList *)malloc(sizeof(GoodsList));
			L = GoodsInfoChange(L);
			L->next = NULL;
			CurrentCnt++;
			*head = L;
			printf("\nSuccessfully Insert!\n");
		}
		printf("\n\n");
		system("pause");
	}
}


//询问用户是否确定其选择
bool check_decision(void)
{
	char sure;
	scanf(" %c", &sure);
	while (getchar() != '\n')   /* skips to end of line */
		;

	if (sure == 'n' || sure == 'N')		return false;			//输入n或N时退出

	else if (sure == 'y' || sure == 'Y')
	{
		return true;
	}

	else
	{
		printf("Unvalidated Input!");
		return false;
	}
}


//以行读取输入的信息
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}


//读取更改后新的信息
GoodsList* GoodsInfoChange(GoodsList *p)
{
	printf("\nPlease enter the new information: ");
	printf("\nID: ");
	read_line(p->data.GoodsInfos_id,MAX_ID_LEN);
	printf("Name: ");
	read_line(p->data.GoodsInfos_name,MAX_NAME_LEN);
	printf("Price: ");
	scanf("%d", &p->data.GoodsInfos_price);
	printf("Discount: ");
	read_line(p->data.GoodsInfos_discount,MAX_DISCOUNT_LEN);
	printf("Amount: ");
	scanf("%d", &p->data.GoodsInfos_amount);
	printf("Remain: ");
	scanf("%d", &p->data.GoodsInfos_remain);
	
	return p;
}


//打印单个商品链表节点的信息
void GoodsInfoPrint(GoodsList *p)
{
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID:%s\t\tName:%s\tPrice:%d\tDiscount:%s\t  Number:%d\tRemain:%d\n", (p->data).GoodsInfos_id, (p->data).GoodsInfos_name,
							(p->data).GoodsInfos_price, (p->data).GoodsInfos_discount, (p->data).GoodsInfos_amount, (p->data).GoodsInfos_remain);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}


//寻找单个商品的位置及信息
bool GoodsInfoSearch(GoodsList **p)
{
	int i;
	char GoodsInfos_id_search[MAX_ID_LEN];
	char GoodsInfos_name_search[MAX_ID_LEN];

	printf("Determine the way you want to use 1.ID; 2.Name (-1 to exit): ");		//选择要输入的方式
	scanf("%d", &i);

	switch (i)
	{
		case -1:	return false;			//输入-1时退出

		case 1:		//输入1时按ID查找
		{
			printf("Please enter the id (-1 to exit): ");
			read_line(GoodsInfos_id_search, MAX_ID_LEN);					//输入要修改的id或名称

			if (strcmp(GoodsInfos_id_search, "-1") == 0)								//输入-1时退出
				return false;

			while (*p != NULL)															//查找要修改的商品
			{
				if (strcmp(((*p)->data).GoodsInfos_id, GoodsInfos_id_search) == 0)	break;
				*p = (*p)->next;
			}
			break;
		}

		case 2:		//输入2时按名称查找
		{
			printf("Please enter the name (-1 to exit): ");
			read_line(GoodsInfos_name_search, MAX_NAME_LEN);										//输入要修改的id或名称

			if (strcmp(GoodsInfos_name_search, "-1") == 0)								//输入-1时退出
				return false;

			while (*p != NULL)															//查找要修改的商品
			{
				if (strcmp(((*p)->data).GoodsInfos_name, GoodsInfos_name_search) == 0)	break;
				*p = (*p)->next;
				break;
			}
			break;
		}

		default:
		{
			printf("Unvalidated Input!");
			return false;
		}
	}

	if (*p == NULL)					//无法找到该商品信息
	{
		printf("Sorry, this good can't be found.");
		return false;
	}

	else
	{
		GoodsInfoPrint(*p);			//打印该商品的信息
		return true;
	}
}

//删除所有商品的链表
void GoodsInfoDestroy(GoodsList **L)
{
	GoodsList *p,*q;
	p = q = *L;

	while (p)
	{
		q = p;
		p = q->next;
		free(q);
		q = NULL;
	}

	*L = NULL;

	CurrentCnt = 0;
}


//1.显示所有商品的信息
void info_output_all(GoodsList *L)
{
	NoGoodsStored(&L);				//当没有商品信息时，提醒用户输入数据

	while (L)
	{
		GoodsInfoPrint(L);			//打印单个商品信息
		L = L->next;
	}
}


//2.查找一条商品记录
void info_search(GoodsList *L) 
{
	NoGoodsStored(&L);				//当没有商品记录时，提醒用户输入商品信息
	GoodsInfoSearch(&L);			//查找商品
}


//3.修改一条商品记录
void info_change(GoodsList **L) 
{
	GoodsList *p;
	p = *L;

	NoGoodsStored(&p);				//当没有商品信息时，提醒用户输入数据

	if (!GoodsInfoSearch(&p))		//找到商品的位置
		return;

	p = GoodsInfoChange(p);			//修改信息
	printf("\nSucceessful Change! The changed information: ");
	GoodsInfoPrint(p);
}


//4.添加一条商品记录
void info_insert(GoodsList **L) 
{
	if (CurrentCnt == MAX)
	{
		printf("Cannot Insert!!");
		return;
	}

	GoodsList *p, *pre;
	p = (GoodsList *)malloc(sizeof(GoodsInfo));
	pre = *L;

	int code;
	printf("Enter where you want to insert (0.head 1.tail i.ith): ");		//选择要插入的位置
	scanf("%d", &code);

	if (code > CurrentCnt)				//选择插入的位置 大于 该商品的数量 时
	{
		printf("Cannot insert!!");
		return;
	}

	p = GoodsInfoChange(p);				//输入要插入的信息

	if (code == 0)						//插入头部
	{
		p->next = *L;
		*L = p;
	}

	else if (code == 1)					//插入尾部
	{
		while (pre->next)
			pre = pre->next;
		pre->next = p;
		p->next = NULL;
	}

	else								//插入到中间的位置
	{
		int i = 1;
		while (i < code - 1)
		{
			pre = pre->next;
			++i;
		}
		p->next = pre->next;
		pre->next = p;
	}
	CurrentCnt++;

	printf("Successfully Insert!\n");		//提示成功插入

	return;
}


//5.对商品价格进行排序
void info_bubble_sort(GoodsList **L) 
{
	NoGoodsStored(L);				//当没有商品信息时，提醒用户输入数据

	GoodsList *p, *pre;
	pre = (GoodsList *)malloc(sizeof(GoodsInfo));

	for (int i = 1; i < CurrentCnt; ++i)
	{
		p = *L;												//下一个循环结束后又从头开始进行排序
		for (int j = 1; j < CurrentCnt - i + 1; ++j)
		{
			if ((p->data).GoodsInfos_price > (p->next->data).GoodsInfos_price)			//价格大的往后调整
			{
				pre->data = p->data;
				p->data = p->next->data;
				p->next->data = pre->data;
			}
			p = p->next;
		}
	}
	printf("\nSuccessfully Sorted!\n");
}


//6.删除一条商品记录
void info_dele(GoodsList **L) 
{
	GoodsList *p, *q;
	p = q = *L;

	if (!GoodsInfoSearch(&p))		//查找商品		
		return;						//找不到商品时，返回

	printf("\nSure to delete? (y/n): ");				//询问用户是否确定删除
	if (!check_decision())
		return;

	
	
	for (; q->next != p && q->next != NULL; q = q->next);		//找到该节点

	if ((q->next)->next == NULL)		//当删除的是最后一个节点时
	{
		p = q->next;
		q->next = NULL;
		free(p);
		p = NULL;
	}
	else
	{
		p = q->next;												//释放该节点
		q->next = p->next;
		free(p);
		p = NULL;
	}
	

	CurrentCnt--;
	printf("Successfully delete!");
}


//7.删除商品文件以及商品链表中的所有信息
void info_del_all(GoodsList **L) 
{
	printf("\nSure to delete? (y/n): ");		//询问用户是否确定删除
	if (!check_decision())	
		return;

	GoodsInfoDestroy(L);						//销毁链表

	remove("GoodsInfo.txt");					//删除文件
	printf("\nSuccessful Deleted.\n\n");
	return;
}


//8.将当前商品链表中的内容存入商品文件GoodsInfo.txt，存盘后销毁链表L
void info_flush(GoodsList **L) 
{
	GoodsList *p;
	p = *L;

	FILE *fp;
	fp = fopen("goodsinfo.txt", "w");

	int savecount = 0;

	while (p)		//将数据存入文件
	{
		fprintf(fp, "%s\t%s\t%d\t%s\t%d\t%d", (p->data).GoodsInfos_id, (p->data).GoodsInfos_name, (p->data).GoodsInfos_price,
			(p->data).GoodsInfos_discount, (p->data).GoodsInfos_amount, (p->data).GoodsInfos_remain);
		++savecount;
		p = p->next;
		if (p != NULL)		fprintf(fp, "\n");					//换行
	}

	printf("%d goods has been saved.\n", savecount);
	fclose(fp);

	GoodsInfoDestroy(L);
}


//主菜单栏
void menu()
{
	printf("Supermarket Commodity Management System\n");
	printf("*********************************************************************\n");
	printf("1.Display All.\n");
	printf("2.search  One.\n");
	printf("3.Modify  One.\n");
	printf("4.Insert  One.\n");
	printf("5.Sort by price.\n");
	printf("6.Delete  One.\n");
	printf("7.Delete  All.(with caution!!) \n");
	printf("8.Save & Exit.\n\n");
	printf("Else.EXIT WITHOUT SAVING.\n");
	printf("*********************************************************************\n\n");
	printf("Please enter your choice: ");
}
