#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void info_init(void);						/*读入信息*/
void info_flush(void);						/*储存信息*/
void OutputAll(void);						/*打印全部信息*/
void info_output(int i);					/*打印单个信息*/
void info_change(void);						/*录入某个信息*/
void info_dele(void);						/*删除某个信息*/
void info_search(void);						/*查找某个信息*/
void info_insert(void);						/*插入某个信息*/
void printmenu(void);						/*欢迎菜单*/
void p_support(void);						/*退出菜单*/

typedef struct {
	char good_id[30];
	char good_name[30];
	int good_amount;
	float good_discount;
}GoodInfo;

GoodInfo * Goods[MAX];
int count = 0;

int main(void)
{
	int choice, c, id;
	info_init();
	while (1)
	{
		printmenu();
		printf("\n请输入您的选择：");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:							/*显示商品信息*/
		{
			OutputAll();
			break;
		}
		case 2:							/*商品信息录入*/
		{
			info_insert();
			break;
		}
		case 3:							/*商品信息修改*/
		{
			info_change();
			break;
		}
		case 4:							/*商品信息删除*/
		{
			info_dele();
			break;
		}
		case 5:							/*商品信息查找*/
		{
			info_search();
			break;
		}
		case 6:							/*保存并且退出*/
		{
			info_flush();
			p_support();
			system("Pause");
			return 0;
		}
		default: printf("非法命令，请重新输入。\n");
		}

	}
}

void info_init(void)						/*读入信息*/
{
	FILE *fp;
	int i = 0;
	GoodInfo temp_item, *pGood;
	if ((fp = fopen("INFO", "ab+")) == NULL)
	{
		perror("file open failure");
		exit(-1);
	}
	while (fread(&temp_item, sizeof(GoodInfo), 1, fp) == 1)
	{
		if (count < MAX)
		{
			pGood = (GoodInfo *)malloc(sizeof(GoodInfo));
			if (pGood != NULL)
			{
				*pGood = temp_item;
				Goods[i] = pGood;
				i++;
				count++;
			}
			else
			{
				printf("存储分配失败！\n");
			}
		}
		else
		{
			printf("数据过多，无法加载！");
			break;
		}
	}
	fclose(fp);
}

void info_flush(void)						/*储存信息*/
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("INFO", "wb")) == NULL)
	{
		printf("can't open datafile.\n");
	}
	else
	{
		while (i < count && fwrite(Goods[i], sizeof(GoodInfo), 1, fp) == 1)
			i++;
	}
	fclose(fp);
}

void OutputAll(void)						/*打印全部信息*/
{
	int i;
	printf("%-10s%-10s%-10s%-10s\n", "商品ID", "商品名", "数量", "折扣");

	for (i = 0; i < count; i++)
	{
		printf("%-10s%-10s%-10d%-10g\n", Goods[i]->good_id, Goods[i]->good_name, Goods[i]->good_amount, Goods[i]->good_discount);
	}

	printf("\n\n输出结束\n\n\n");
}

void info_output(int i)						/*打印单个信息*/
{
	printf("%-10s%-10s%-10s%-10s\n", "商品ID", "商品名", "数量", "折扣");
	printf("%-10s%-10s%-10d%-10g\n", Goods[i]->good_id, Goods[i]->good_name, Goods[i]->good_amount, Goods[i]->good_discount);
	printf("\n\n输出结束\n\n\n");
}

void info_change(void)						/*修改某个信息*/
{
	char a[20], ch[20];
	int i, t, m = 0;

	printf("请输入商品ID：");
	scanf_s("%s", a);

	for (i = 0; i < count; i++)
	{
		if (strcmp(&Goods[i]->good_id, a) == 0)
		{
			m++;
			t = i;
		}

	}

	if (m == 0)
		printf("你输入的商品ID不存在。正在返回主菜单。\n\n");
	else if (m == 1)
	{
		printf("\n是否改变商品名(y/n):");
		scanf_s("%s", ch);

		if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
		{
			printf("\n请输入新的商品名:");
			scanf_s("%s", &Goods[t]->good_name);
		}

		printf("\n是否改变商品数量(y/n): ");
		scanf_s("%s", ch);

		if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
		{
			printf("\n请输入商品数量:");
			scanf_s("%d", &Goods[t]->good_amount);
		}

		printf("\n是否改变商品折扣(y/n):");
		scanf_s("%s", ch);

		if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
		{
			printf("\n请输入新的折扣:");
			scanf_s("%f", &Goods[t]->good_discount);
		}
	}
}

void info_dele(void)						/*删除某个信息*/
{
	int i, j, t, m = 0;
	char ch[20], a[20];

	printf("\n请输入商品ID来删除商品（如果要删除全部信息请删除目录下INFO文件）：");
	scanf_s("%s", ch);

	for (i = 0; i < count; i++)
	{
		if (strcmp(&Goods[i]->good_id, ch) == 0)
		{
			m++;
			t = i;
		}
	}

	if (m == 0)
		printf("您输入的商品ID不存在，正在返回主菜单\n\n");
	else
	{
		printf("**********  您要删除的商品是：***********\n");
		info_output(t);
		printf("请确认是否无误(y/n)：");
		scanf_s("%s", a);

		if (strcmp(a, "y") == 0 || strcmp(a, "Y") == 0)
		{
			for (j = t; j < count - 1; j++)
				Goods[j] = Goods[j + 1];
			count--;
			printf("\n删除成功，正在返回主菜单\n");
		}
		else
		{
			printf("\n正在返回主菜单\n\n");
		}
	}
}

void info_search(void)						/*查找某个信息*/
{
	int b, i, n, t, m = 0;
	char a[20], num[20];

	printf("按商品ID来查找选1\n");
	printf("按商品名来查找选2\n");
	printf("请输入您的选择：");
	scanf_s("%d", &b);

	switch (b)
	{
	case 1:
	{
		printf("请输入商品ID：");
		scanf_s("%s", a);

		for (i = 0; i < count; i++)
		{
			if (strcmp(&Goods[i]->good_id, a) == 0)
			{
				m++;
				t = i;
			}
		}

		if (m == 0)
			printf("您输入的商品ID不存在，正在返回主菜单\n\n");
		else
		{
			printf("**********  您要查找的商品是：***********\n");
			info_output(t);
		}
		break;
	}
	case 2:
	{
		printf("请输入商品名：");
		scanf_s("%s", a);

		for (i = 0; i < count; i++)
		{
			if (strcmp(&Goods[i]->good_name, a) == 0)
			{
				m++;
				t = i;
			}
		}

		if (m == 0)
			printf("您输入的商品名不存在，正在返回主菜单\n\n");
		else
		{
			printf("**********  您要查找的商品是：***********\n");
			info_output(t);
		}
		break;
	}
	default: printf("错误的指令，正在返回主菜单\n"); break;
	}
}

void info_insert(void)						/*录入某个信息*/
{
	GoodInfo * temp_item;
	char choose[10];

Again:
	if (count < MAX)
	{
		temp_item = (GoodInfo*)malloc(sizeof(GoodInfo));

		if (temp_item == NULL)
		{
			printf("error!");
		}
		else
		{
			printf("商品ID：");
			scanf_s("%s", temp_item->good_id);
			printf("商品名：");
			scanf_s("%s", temp_item->good_name);
			printf("数量：");
			scanf_s("%d", &(temp_item->good_amount));
			printf("折扣：");
			scanf_s("%f", &(temp_item->good_discount));
			Goods[count] = temp_item;
			count++;
		}

		printf("是否继续录入数据(y/n)：");
		scanf("%s", choose);
		if (strcmp(choose, "y") == 0 || strcmp(choose, "Y") == 0)
			goto Again;
	}
	else
	{
		printf("数量过多!");
	}
}

void printmenu(void)
{
	printf("*****************************************\n");
	printf("****** 欢迎使用超市商品信息储存系统 *****\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("**************** 功能菜单 ***************\n");
	printf("*****************************************\n");
	printf(" 1：显示商品信息 \n");
	printf(" 2：商品信息录入 \n");
	printf(" 3：商品信息修改 \n");
	printf(" 4：商品信息删除 \n");
	printf(" 5：商品信息查找 \n");
	printf(" 6：保存并且退出 \n");
}

void p_support(void)
{
	printf("*****************************************\n");
	printf("************** 文件保存成功 *************\n");
	printf("************** 感谢您的使用 *************\n");
	printf("*****************************************\n");
}

