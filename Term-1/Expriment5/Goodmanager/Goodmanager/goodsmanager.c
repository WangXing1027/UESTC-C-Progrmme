#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100								//��Ʒ���������
int CurrentCnt = 0;						//ȫ�ֱ������洢��ǰ��Ʒ������

//��Ʒ��Ϣ�ṹ�Ķ���
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

bool check_nullfile(void);						//�����Ʒ�ļ��Ƿ���ڻ����Ƿ�Ϊ��
void info_init(GoodsList **head);				//��ȡ��Ʒ�ļ�GoodsInfo.txt������,����������L

int read_line(char str[], int n);				//���ж�ȡ�������Ϣ
void menu();									//���˵���
void NoGoodsStored(GoodsList **head);			//��û����Ʒ��Ϣʱ,�����û�¼������
bool check_decision(void);						//ѯ���û��Ƿ�ȷ����ѡ��

GoodsList* GoodsInfoChange(GoodsList *p);		//��ȡ���ĺ��µ���Ϣ
void GoodsInfoPrint(GoodsList *p);				//��ӡ������Ʒ����ڵ����Ϣ
bool GoodsInfoSearch(GoodsList **p);			//Ѱ�ҵ�����Ʒ��λ�ü���Ϣ
void GoodsInfoDestroy(GoodsList **L);			//ɾ��������Ʒ������

void info_output_all(GoodsList *L);				//1.��ʾ������Ʒ����Ϣ
void info_search(GoodsList *L);					//2.����һ����Ʒ��¼
void info_change(GoodsList **L);				//3.�޸�һ����Ʒ��¼
void info_insert(GoodsList **L);				//4.���һ����Ʒ��¼
void info_bubble_sort(GoodsList **L);			//5.����Ʒ�۸��������
void info_dele(GoodsList **L);					//6.ɾ��һ����Ʒ��¼
void info_del_all(GoodsList **L);				//7.ɾ����Ʒ�ļ�����Ϣ
void info_flush(GoodsList **L);					//8.�������ݲ��˳�


//������
int main()
{
	GoodsList *L = NULL;

	char choice;
	info_init(&L);					//��ȡ��Ʒ�ļ�����������

	NoGoodsStored(&L);				//��û������ʱ�����û���������

	while (1)
	{
		menu();

		scanf(" %c", &choice);
		while (getchar() != '\n')   /* skips to end of line */
			;

		switch (choice)
		{
		case '1':					//1.��ʾ������Ʒ����Ϣ
			info_output_all(L);
			break;
		case '2':					//2.����ĳ����Ʒ����Ϣ
			info_search(L);
			break;
		case '3':					//3.�޸�ĳ����Ʒ����Ϣ
			info_change(&L);
			break;
		case '4':					//4.����ĳ����Ʒ����Ϣ
			info_insert(&L);
			break;
		case '5':					//5.����Ʒ�۸��������
			info_bubble_sort(&L);
			break;
		case '6':					//6.ɾ��ĳ����Ʒ����Ϣ
			info_dele(&L);
			break;
		case '7':					//7.�����ã�ɾ����������
			info_del_all(&L);
			return 0;
		case '8':					//8.��Ʒ���̲��˳�ϵͳ
			info_flush(&L);
			return 0;
		default:					//����
			return 0;
		}

		puts("\n");
		system("Pause");
		system("cls");
	}

	return 0;
}


//�����Ʒ�ļ��Ƿ���ڻ����Ƿ�Ϊ��
bool check_nullfile(void)
{
	FILE *fp = fopen("GoodsInfo.txt", "r");

	if (!fp)		//�ļ�������
	{
		printf("The product information initialization file doesn't exist!!\n");
		printf("The program will create a new one for you.\n\n");

		FILE *fp = fopen("GoodsInfo.txt", "w");
		fclose(fp);

		return false;
	}
	else				//�ļ�����
	{
		int temp;		//�ж��ļ��Ƿ�Ϊ��
		int res = fscanf(fp, "%d", &temp);
		fclose(fp);
		if (res <= 0)
			return false;
		else
			return true;
	}
}


//��ȡ��Ʒ�ļ�GoodsInfo.txt������,����������L
void info_init(GoodsList **head)
{
	GoodsList *pre, *p;
	pre = (GoodsList *)malloc(sizeof(GoodsList));

	if (check_nullfile())							//�ж��ļ��Ƿ���ڣ������Ҳ�Ϊ���򷵻�1
	{
		FILE *fp = fopen("GoodsInfo.txt", "r");

		while (!feof(fp))
		{

			p = (GoodsList *)malloc(sizeof(GoodsList));

			if (*head == NULL)		//ͷ�ڵ�
				*head = p;

			else					//�����ṹ
				pre->next = p;

			p->next = NULL;
			pre = p;
			fscanf(fp, "%s%s%d%s%d%d\t", (p->data).GoodsInfos_id, (p->data).GoodsInfos_name, &(p->data).GoodsInfos_price,
									 &(p->data).GoodsInfos_discount, &(p->data).GoodsInfos_amount, &(p->data).GoodsInfos_remain);
			++CurrentCnt;

			if (CurrentCnt > MAX)
			{
				printf("Too Many Commedies!Cannot load!");		//��Ʒ��Ϣ����
				exit(-1);
			}
		}

		fclose(fp);
	}
	
	printf("The list of items has been created. %d commodities have been recorded.\n\n", CurrentCnt);
}


//��û����Ʒ��Ϣʱ,�����û�¼������
void NoGoodsStored(GoodsList **head)
{
	if (*head == NULL)
	{
		printf("Sorry, No Good Stored! Whether to insert one? (y/n): ");

		if (check_decision())				//ȷ���û��Ƿ�ѡ�������Ʒ��Ϣ
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


//ѯ���û��Ƿ�ȷ����ѡ��
bool check_decision(void)
{
	char sure;
	scanf(" %c", &sure);
	while (getchar() != '\n')   /* skips to end of line */
		;

	if (sure == 'n' || sure == 'N')		return false;			//����n��Nʱ�˳�

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


//���ж�ȡ�������Ϣ
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


//��ȡ���ĺ��µ���Ϣ
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


//��ӡ������Ʒ����ڵ����Ϣ
void GoodsInfoPrint(GoodsList *p)
{
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID:%s\t\tName:%s\tPrice:%d\tDiscount:%s\t  Number:%d\tRemain:%d\n", (p->data).GoodsInfos_id, (p->data).GoodsInfos_name,
							(p->data).GoodsInfos_price, (p->data).GoodsInfos_discount, (p->data).GoodsInfos_amount, (p->data).GoodsInfos_remain);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}


//Ѱ�ҵ�����Ʒ��λ�ü���Ϣ
bool GoodsInfoSearch(GoodsList **p)
{
	int i;
	char GoodsInfos_id_search[MAX_ID_LEN];
	char GoodsInfos_name_search[MAX_ID_LEN];

	printf("Determine the way you want to use 1.ID; 2.Name (-1 to exit): ");		//ѡ��Ҫ����ķ�ʽ
	scanf("%d", &i);

	switch (i)
	{
		case -1:	return false;			//����-1ʱ�˳�

		case 1:		//����1ʱ��ID����
		{
			printf("Please enter the id (-1 to exit): ");
			read_line(GoodsInfos_id_search, MAX_ID_LEN);					//����Ҫ�޸ĵ�id������

			if (strcmp(GoodsInfos_id_search, "-1") == 0)								//����-1ʱ�˳�
				return false;

			while (*p != NULL)															//����Ҫ�޸ĵ���Ʒ
			{
				if (strcmp(((*p)->data).GoodsInfos_id, GoodsInfos_id_search) == 0)	break;
				*p = (*p)->next;
			}
			break;
		}

		case 2:		//����2ʱ�����Ʋ���
		{
			printf("Please enter the name (-1 to exit): ");
			read_line(GoodsInfos_name_search, MAX_NAME_LEN);										//����Ҫ�޸ĵ�id������

			if (strcmp(GoodsInfos_name_search, "-1") == 0)								//����-1ʱ�˳�
				return false;

			while (*p != NULL)															//����Ҫ�޸ĵ���Ʒ
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

	if (*p == NULL)					//�޷��ҵ�����Ʒ��Ϣ
	{
		printf("Sorry, this good can't be found.");
		return false;
	}

	else
	{
		GoodsInfoPrint(*p);			//��ӡ����Ʒ����Ϣ
		return true;
	}
}

//ɾ��������Ʒ������
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


//1.��ʾ������Ʒ����Ϣ
void info_output_all(GoodsList *L)
{
	NoGoodsStored(&L);				//��û����Ʒ��Ϣʱ�������û���������

	while (L)
	{
		GoodsInfoPrint(L);			//��ӡ������Ʒ��Ϣ
		L = L->next;
	}
}


//2.����һ����Ʒ��¼
void info_search(GoodsList *L) 
{
	NoGoodsStored(&L);				//��û����Ʒ��¼ʱ�������û�������Ʒ��Ϣ
	GoodsInfoSearch(&L);			//������Ʒ
}


//3.�޸�һ����Ʒ��¼
void info_change(GoodsList **L) 
{
	GoodsList *p;
	p = *L;

	NoGoodsStored(&p);				//��û����Ʒ��Ϣʱ�������û���������

	if (!GoodsInfoSearch(&p))		//�ҵ���Ʒ��λ��
		return;

	p = GoodsInfoChange(p);			//�޸���Ϣ
	printf("\nSucceessful Change! The changed information: ");
	GoodsInfoPrint(p);
}


//4.���һ����Ʒ��¼
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
	printf("Enter where you want to insert (0.head 1.tail i.ith): ");		//ѡ��Ҫ�����λ��
	scanf("%d", &code);

	if (code > CurrentCnt)				//ѡ������λ�� ���� ����Ʒ������ ʱ
	{
		printf("Cannot insert!!");
		return;
	}

	p = GoodsInfoChange(p);				//����Ҫ�������Ϣ

	if (code == 0)						//����ͷ��
	{
		p->next = *L;
		*L = p;
	}

	else if (code == 1)					//����β��
	{
		while (pre->next)
			pre = pre->next;
		pre->next = p;
		p->next = NULL;
	}

	else								//���뵽�м��λ��
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

	printf("Successfully Insert!\n");		//��ʾ�ɹ�����

	return;
}


//5.����Ʒ�۸��������
void info_bubble_sort(GoodsList **L) 
{
	NoGoodsStored(L);				//��û����Ʒ��Ϣʱ�������û���������

	GoodsList *p, *pre;
	pre = (GoodsList *)malloc(sizeof(GoodsInfo));

	for (int i = 1; i < CurrentCnt; ++i)
	{
		p = *L;												//��һ��ѭ���������ִ�ͷ��ʼ��������
		for (int j = 1; j < CurrentCnt - i + 1; ++j)
		{
			if ((p->data).GoodsInfos_price > (p->next->data).GoodsInfos_price)			//�۸����������
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


//6.ɾ��һ����Ʒ��¼
void info_dele(GoodsList **L) 
{
	GoodsList *p, *q;
	p = q = *L;

	if (!GoodsInfoSearch(&p))		//������Ʒ		
		return;						//�Ҳ�����Ʒʱ������

	printf("\nSure to delete? (y/n): ");				//ѯ���û��Ƿ�ȷ��ɾ��
	if (!check_decision())
		return;

	
	
	for (; q->next != p && q->next != NULL; q = q->next);		//�ҵ��ýڵ�

	if ((q->next)->next == NULL)		//��ɾ���������һ���ڵ�ʱ
	{
		p = q->next;
		q->next = NULL;
		free(p);
		p = NULL;
	}
	else
	{
		p = q->next;												//�ͷŸýڵ�
		q->next = p->next;
		free(p);
		p = NULL;
	}
	

	CurrentCnt--;
	printf("Successfully delete!");
}


//7.ɾ����Ʒ�ļ��Լ���Ʒ�����е�������Ϣ
void info_del_all(GoodsList **L) 
{
	printf("\nSure to delete? (y/n): ");		//ѯ���û��Ƿ�ȷ��ɾ��
	if (!check_decision())	
		return;

	GoodsInfoDestroy(L);						//��������

	remove("GoodsInfo.txt");					//ɾ���ļ�
	printf("\nSuccessful Deleted.\n\n");
	return;
}


//8.����ǰ��Ʒ�����е����ݴ�����Ʒ�ļ�GoodsInfo.txt�����̺���������L
void info_flush(GoodsList **L) 
{
	GoodsList *p;
	p = *L;

	FILE *fp;
	fp = fopen("goodsinfo.txt", "w");

	int savecount = 0;

	while (p)		//�����ݴ����ļ�
	{
		fprintf(fp, "%s\t%s\t%d\t%s\t%d\t%d", (p->data).GoodsInfos_id, (p->data).GoodsInfos_name, (p->data).GoodsInfos_price,
			(p->data).GoodsInfos_discount, (p->data).GoodsInfos_amount, (p->data).GoodsInfos_remain);
		++savecount;
		p = p->next;
		if (p != NULL)		fprintf(fp, "\n");					//����
	}

	printf("%d goods has been saved.\n", savecount);
	fclose(fp);

	GoodsInfoDestroy(L);
}


//���˵���
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
