#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>


//定义学生数据节点类型
typedef struct{
    char sno[12];       //学号
    char sname[10];     //名字
    char sex[4];        //性别
    char major[20];     //专业
}Sinfo;

//定义学生链表节点
typedef struct Snode{
    Sinfo data;          //数据域
    struct Snode* next;      //指针域
}Slist;

//定义学生表
typedef struct Stable{
    int rows;
    int cols;
    Slist *snode;    //学生信息节点
}Stable;

//定义课程结构类型
typedef struct{
    char cno[10];       //课程代码
    char cname[20];     //课程名称
    int classhours;     //课程时长
}Cinfo;

//定义课程链表节点
typedef struct Cnode{
    Cinfo data;             //数据域
    struct Cnode* next;     //指针域
}Clist;

//定义课程表
typedef struct{
    int rows;       //课程表行数
    int cols;       //课程表列数
    Clist *cnode;   //课程表信息节点
}Ctable;

//定义成绩表数据类型
typedef struct{
    char sno[12];       //学生姓名 
    char cno[10];       //课程名
    int score;          //课程成绩
}Ginfo;

//定义成绩链表节点
typedef struct Gnode{
    Ginfo data;             //数据域
    struct Gnode *next;     //指针域
}Glist;

//定义成绩表
typedef struct{
    int rows;       //列数
    int cols;       //行数
    Glist *gnode;   //成绩信息节点
}Gtable;

typedef struct{
    char sno[12];
    char sname[20];
    char major[20];
    char cname[20];
    int score;
}SCGinfo;

typedef struct SCGnode{
    SCGinfo data;
    struct SCGnode *next;
}SCGlist;

typedef struct{
    int rows;
    int cols;
    SCGlist *scgnode;
}SCGtable;

typedef struct stacknode{
    Sinfo data;
    struct stacknode *next;
}STACKNODE;

typedef struct{
    STACKNODE *pTop;
    STACKNODE *pBottom;
}STACK;

typedef struct queuenode{
    SCGinfo data;
    struct queuenode *next;
}QUENODE;

typedef struct{
    QUENODE *front;
    QUENODE *rear;
    int len;
}QUE;

int read_line(char str[], int n);
bool check_nullfile(char *filename);
void snode_input(Slist **p);
void stu_info_input();
void stu_init(Stable **pstu);
void stu_output_all(Stable *pre);
void stu_sorted(Stable **pstu);
void cnode_input(Clist **p);
void cou_info_input();
void cou_init(Ctable **pcou);
void cou_output_all(Ctable *pre);
void cou_sorted(Ctable **pcou);
void gnode_input(Glist **p);
void gra_info_input(Stable *pstu,Ctable *pcou);
void gra_init(Gtable **pgra);
void gra_output_all(Gtable *pre);
void gra_sno_sorted(Gtable **pgra);
void gra_score_sorted(SCGtable **pscg);
void gra_stu_search(Stable *pstu,Ctable *pcou,Gtable *pgra);
SCGtable *scg_init(Stable *pstu,Ctable *pcou,Gtable *pgra);
bool isempty_stack(STACK *ps);
void init_stack(STACK **ps);
void push_stack(STACK **ps,Stable *pstu);
Stable* pop_stack(STACK **ps);
void stack(Stable *pstu);
bool isempty_queue(QUE *que);
void en_queue(QUE **que,SCGtable *pscg);
void que(SCGtable *pscg);
void scg_output_all(SCGtable *pscg);
void meue();


//检查文件是否存在或者是否为空
bool check_nullfile(char *filename)
{
	FILE *fp = fopen(filename, "r");

	if (!fp)		//文件不存在
	{
		printf("The %s doesn't exist!!\n",filename);
		return false;
	}
    
	else				//文件存在
	{   
        return true;
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

//单个学生信息输入
void snode_input(Slist **p){
    printf("Please enter the student's ID: ");
    read_line((*p)->data.sno,12);
    printf("Please enter the student's name: ");
    read_line((*p)->data.sname,10);
    printf("Please enter the student's sex: ");
    read_line((*p)->data.sex,4);
    printf("Please enter the student's magor: ");
    read_line((*p)->data.major,20);
}

//10个学生信息输入
void stu_info_input(){
    FILE *fp = fopen("student.dat", "w");       //写文件
    for(int i = 0; i < 10; ++i){
        Slist* p = (Slist*)malloc(sizeof(Slist));
        snode_input(&p);                   //单个节点的信息输入
        fprintf(fp,"%s\t%s\t%s\t%s\t",p->data.sno,p->data.sname,p->data.sex,p->data.major);
        if(i != 9)  fprintf(fp,"\n");      //除开最后一行外，空行
    }
    fclose(fp);
}

//读取学生信息，并创建链表
void stu_init(Stable **pstu){
        *pstu = (Stable*)malloc(sizeof(Stable));
        (*pstu)->rows = 0;
        (*pstu)->cols= 0;
        (*pstu)->snode = NULL;

    	if (check_nullfile("student.dat"))							//判断文件是否存在，存在且不为空则返回1
        {
            FILE *fp = fopen("student.dat", "r");
        
            Slist* pre = (Slist*)malloc(sizeof(Slist));

            while(!feof(fp)){
                Slist* p = (Slist*)malloc(sizeof(Slist));
                if((*pstu)->snode == NULL){
                    (*pstu)->snode = p;
                }
                else{
                    pre->next = p;
                }
                p->next = NULL;
                pre = p;
                fscanf(fp, "%s%s%s%s\n",p->data.sno,p->data.sname,p->data.sex,p->data.major);
                ++(*pstu)->rows;
                (*pstu)->cols = 4;
            }

            fclose(fp);
        }
        else{
            printf("Please enter the information first!");
            system("pause");
            exit(0);
        }
}


//学生节点信息全部打印
void stu_output_all(Stable *pstu){
    Slist *p = pstu->snode;
    printf("\t\tSTUDENTS' INFORMATION\n----------------------------------------------------------\nID\t\tNAME\t\tSEX\t\tMAJOR\t\t\n");
    while(p){
        printf("%s\t\t%s\t\t%s\t\t%s\t\t\n",p->data.sno,p->data.sname,p->data.sex,p->data.major);
        p = p->next;
    }
    printf("----------------------------------------------------------\n\n");
}

//按照学生学号升序进行冒泡排序法
void stu_sorted(Stable **pstu){
    Slist *p = (*pstu)->snode;
    for(int i = 1; i < (*pstu)->rows; ++i){
        for( int j = 0; j < (*pstu)->rows-i; ++j){
            if(strcmp(p->data.sno,p->next->data.sno) > 0){
                Slist *temp = (Slist*)malloc(sizeof(Slist));
                temp->data = p->data;
                p->data = p->next->data;
                p->next->data = temp->data;
            }
            p = p->next;
        }
        p = (*pstu)->snode;
    }
}


//单个课程信息输入
void cnode_input(Clist **p){
    printf("Please enter the course's ID: ");
    read_line((*p)->data.cno,10);
    printf("Please enter the course's name: ");
    read_line((*p)->data.cname,20);
    printf("Please enter the course's hour: ");
    scanf("%d",&(*p)->data.classhours);
}

//3个课程信息输入
void cou_info_input(){
    FILE *fp = fopen("course.dat", "w");       //写文件
    for(int i = 0; i < 3; ++i){
        Clist* p = (Clist*)malloc(sizeof(Clist));
        cnode_input(&p);                   //单个节点的信息输入
        fprintf(fp,"%s\t%s\t%d\t",p->data.cno,p->data.cname,p->data.classhours);
        if(i != 2)  fprintf(fp,"\n");      //除开最后一行外，空行
    }
    fclose(fp);
}


//读取课程信息，并创建课程链表
void cou_init(Ctable **pcou){
        *pcou = (Ctable*)malloc(sizeof(Ctable));
        (*pcou)->rows = 0;
        (*pcou)->cols= 0;
        (*pcou)->cnode = NULL;

    	if (check_nullfile("course.dat"))							//判断文件是否存在，存在且不为空则返回1
        {
            FILE *fp = fopen("course.dat", "r");
        
            Clist* pre = (Clist*)malloc(sizeof(Clist));

            while(!feof(fp)){
                Clist* p = (Clist*)malloc(sizeof(Clist));
                if((*pcou)->cnode == NULL){
                    (*pcou)->cnode = p;
                }
                else{
                    pre->next = p;
                }
                p->next = NULL;
                pre = p;
                fscanf(fp, "%s%s%d\n",p->data.cno,p->data.cname,&p->data.classhours);
                ++(*pcou)->rows;
                (*pcou)->cols = 3;
            }

            fclose(fp);
        }
        else{
            printf("Please enter the information first!");
            system("pause");
            exit(0);
        }
}

//单个课程节点打印
void cnode_output(Clist *p){
    printf("----------------------------------------------------------------------\n");
    printf("ID:%s\t\tNAME:%s\tCLASSHOUR:%d\t\n",p->data.cno,p->data.cname,p->data.classhours);
    printf("----------------------------------------------------------------------\n");
}

//课程节点信息全部打印
void cou_output_all(Ctable *pcou){
    Clist *p = pcou->cnode;
    printf("\t\tCOURSES' INFORMATION\n----------------------------------------------------------\nID\t\tNAME\t\t\tCLASSHOUR\t\t\n");
    while(p){
        printf("ID:%s\t\tNAME:%s\t\tCLASSHOUR:%d\t\n",p->data.cno,p->data.cname,p->data.classhours);
        p = p->next;
    }
    printf("----------------------------------------------------------\n\n");
}

//按照课程号升序进行冒泡排序法
void cou_sorted(Ctable **pcou){
    Clist *p = (*pcou)->cnode;
    for(int i = 1; i < (*pcou)->rows; ++i){
        for( int j = 0; j < (*pcou)->rows-i; ++j){
            if(strcmp(p->data.cno,p->next->data.cno) > 0){
                Clist *temp = (Clist*)malloc(sizeof(Clist));
                temp->data = p->data;
                p->data = p->next->data;
                p->next->data = temp->data;
            }
            p = p->next;
        }
        p = (*pcou)->cnode;
    }
}

//单个成绩信息输入
void gnode_input(Glist **p){
    printf("Please enter the student's ID: ");
    read_line((*p)->data.sno,10);
    printf("Please enter the course's ID: ");
    read_line((*p)->data.cno,20);
    printf("Please enter the score: ");
    scanf("%d",&(*p)->data.score);
}

//30个成绩信息输入
void gra_info_input(Stable *pstu,Ctable *pcou){
    FILE *fp = fopen("courseGrade.dat", "w");       //写文件
    for(int i = 0; i < (pstu->rows)*(pcou->rows); ++i){
        Glist* p = (Glist*)malloc(sizeof(Glist));
        gnode_input(&p);                   //单个节点的信息输入
        fprintf(fp,"%s\t%s\t%d\t",p->data.sno,p->data.cno,p->data.score);
        if(i != 2)  fprintf(fp,"\n");      //除开最后一行外，空行
    }
    fclose(fp);
}

//读取成绩信息，并创建成绩链表
void gra_init(Gtable **pgra){
        *pgra = (Gtable*)malloc(sizeof(Gtable));
        (*pgra)->rows = 0;
        (*pgra)->cols= 0;
        (*pgra)->gnode = NULL;

    	if (check_nullfile("courseGrade.dat"))							//判断文件是否存在，存在且不为空则返回1
        {
            FILE *fp = fopen("courseGrade.dat", "r");
        
            Glist* pre = (Glist*)malloc(sizeof(Glist));

            while(!feof(fp)){
                Glist* p = (Glist*)malloc(sizeof(Glist));
                if((*pgra)->gnode == NULL){
                    (*pgra)->gnode = p;
                }
                else{
                    pre->next = p;
                }
                p->next = NULL;
                pre = p;
                fscanf(fp, "%s%s%d\n",p->data.sno,p->data.cno,&p->data.score);
                ++(*pgra)->rows;
                (*pgra)->cols = 3;
            }

            fclose(fp);
        }
        else{
            printf("Please enter the information first!");
            system("pause");
            exit(0);
        }
}

//成绩节点信息全部打印
void gra_output_all(Gtable *pgra){
    Glist *p = pgra->gnode;
    printf("\t\tGRADES' INFORMATION:\n----------------------------------------------------------\nSTUDENT\t\t\tCOURSE\t\t\tSCORE\t\t\t\n");
    while(p){
        printf("%s\t\t\t%s\t\t\t%d\t\t\n",p->data.sno,p->data.cno,p->data.score);
        p = p->next;
    }
    printf("----------------------------------------------------------\n\n");
}

//按照考试成绩升序进行冒泡排序法
void gra_sno_sorted(Gtable **pgra){
    Glist *p = (*pgra)->gnode;
    //按照学号排列
    for(int i = 1; i < (*pgra)->rows; ++i){
        for( int j = 0; j < (*pgra)->rows-i; ++j){
            if(strcmp(p->data.sno , p->next->data.sno) > 0){
                Glist *temp = (Glist*)malloc(sizeof(Glist));
                temp->data = p->data;
                p->data = p->next->data;
                p->next->data = temp->data;
            }
            p = p->next;
        }
        p = (*pgra)->gnode;
    }
    
    //按照课程号排列
    for(int i = 1; i < (*pgra)->rows; ++i){
        for( int j = 0; j < (*pgra)->rows-i; ++j){
            if(strcmp(p->data.sno , p->next->data.sno) == 0){
                if(strcmp(p->data.cno , p->next->data.cno) > 0){             
                    Glist *temp = (Glist*)malloc(sizeof(Glist));
                    temp->data = p->data;
                    p->data = p->next->data;
                    p->next->data = temp->data;
                }
            }
            p = p->next;
        }   
        p = (*pgra)->gnode;
    }
}

//按照考试成绩降序进行冒泡排序法
void gra_score_sorted(SCGtable **pscg){
    SCGlist *p = (*pscg)->scgnode;
    for(int i = 1; i < (*pscg)->rows; ++i){
        for( int j = 0; j < (*pscg)->rows-i; ++j){
            if(p->data.score < p->next->data.score){
                SCGlist *temp = (SCGlist*)malloc(sizeof(SCGlist));
                temp->data = p->data;
                p->data = p->next->data;
                p->next->data = temp->data;
            }
            p = p->next;
        }
        p = (*pscg)->scgnode;
    }
}

//打印所有成绩信息
void scg_output_all(SCGtable *pscg){
    SCGlist *p = pscg->scgnode;
    printf("\t\t\tINFORMATION\n----------------------------------------------------------------------\nCOURSE\t\tID\t\tNAME\t\tMAJOR\t\tSCORE\t\n");
    while(p){
        printf("%s\t%s\t\t%s\t\t%s\t%d\n",p->data.cname,p->data.sno,p->data.sname,p->data.major,p->data.score);
        p = p->next;
    }
    printf("----------------------------------------------------------------------\n\n");
}

//查询某课程的成绩信息
void gra_stu_search(Stable *pstu,Ctable *pcou,Gtable *pgra){
    char couID[10];
    printf("Enter the course ID: ");
    read_line(couID,10);

    Slist *p = pstu->snode;
    Clist *q = pcou->cnode;
    Glist *r = pgra->gnode;
    SCGtable *pscg = NULL;
    pscg = (SCGtable*)malloc(sizeof(SCGtable));
    pscg->scgnode = NULL;
    pscg->cols = 5;
    pscg->rows = 0;
    SCGlist* pre = (SCGlist*)malloc(sizeof(SCGlist));

    while(q){
        if(strcmp(q->data.cno,couID)==0){
            while(r){                                     //查询课程表中课程
                if(strcmp(r->data.cno,couID)==0){
                    p = pstu->snode;              //查询成功
                    while(p){                                 //查询学生信息
                        if(strcmp(p->data.sno,r->data.sno) == 0){             
                            SCGlist* temp = (SCGlist*)malloc(sizeof(SCGlist));
                            temp->data.score = r->data.score;
                            strcpy(temp->data.sname,p->data.sname);
                            strcpy(temp->data.major,p->data.major);
                            strcpy(temp->data.sno,p->data.sno);
                            strcpy(temp->data.cname,q->data.cname);
                            if(pscg->scgnode == NULL){
                                pscg->scgnode = temp;
                            }
                            else{
                                pre->next = temp;
                            }
                            temp->next = NULL;
                            pre = temp;
                            ++(pscg->rows);
                        }
                        p = p->next;
                    }
                }
                r = r->next;
            }
            break;
        }
        q = q->next;
    }

    gra_score_sorted(&pscg);
    scg_output_all(pscg);       //打印信息

}

//所有考试成绩排列
SCGtable *scg_init(Stable *pstu,Ctable *pcou,Gtable *pgra){
    Slist *p = pstu->snode;
    Clist *q = pcou->cnode;
    Glist *r = pgra->gnode;
    SCGtable *pscg = NULL;
    pscg = (SCGtable*)malloc(sizeof(SCGtable));
    pscg->scgnode = NULL;
    pscg->cols = 5;
    pscg->rows = 0;
    SCGlist* pre = (SCGlist*)malloc(sizeof(SCGlist));

    while(q){
        r = pgra->gnode;
        while(r){                                     //查询课程表中课程
            if(strcmp(r->data.cno,q->data.cno)==0){
                p = pstu->snode;                        //查询成功
                while(p){                                 //查询学生信息
                    if(strcmp(p->data.sno,r->data.sno) == 0){             
                        SCGlist* temp = (SCGlist*)malloc(sizeof(SCGlist));
                        temp->data.score = r->data.score;
                        strcpy(temp->data.sname,p->data.sname);
                        strcpy(temp->data.major,p->data.major);
                        strcpy(temp->data.sno,p->data.sno);
                        strcpy(temp->data.cname,q->data.cname);
                        if(pscg->scgnode == NULL){
                            pscg->scgnode = temp;
                        }
                        else{
                            pre->next = temp;
                        }
                        temp->next = NULL;
                        pre = temp;
                        ++(pscg->rows);
                    }
                    p = p->next;
                }
            }
            r = r->next;
        }   
        q = q->next;
    }

    gra_score_sorted(&pscg);

    FILE *fp = fopen("studentGrade.dat", "w");       //写文件
    SCGlist *node = pscg->scgnode;      //表示单个节点
    while(node){
        fprintf(fp,"%s\t%s\t%s\t%s\t%d\t",node->data.cname,node->data.sno,node->data.sname,node->data.major,node->data.score);
        if(node->next != NULL)  fprintf(fp,"\n");      //除开最后一行外，空行
        node = node->next;
    }
    fclose(fp);
    return pscg;
}

void gra_below_sixty(SCGtable *pscg){
    SCGlist *p = pscg->scgnode;
    SCGlist* pre = (SCGlist*)malloc(sizeof(SCGlist));
    SCGtable* belowsixty = (SCGtable*)malloc(sizeof(SCGtable));
    belowsixty->cols = 5;
    belowsixty->rows = 0;
    belowsixty->scgnode = NULL;
    while(p){
        if(p->data.score < 60){
            SCGlist* temp = (SCGlist*)malloc(sizeof(SCGlist));
            temp->data = p->data;
            if(belowsixty->scgnode == NULL){
                belowsixty->scgnode = temp;
            }
            else{
                pre->next = temp;
            }
            temp->next = NULL;
            pre = temp;
            ++(belowsixty->rows);
        }
        p = p->next;
    }
    scg_output_all(belowsixty);
}

//站的判空操作
bool isempty_stack(STACK *ps){
    return ps->pTop == ps->pBottom;
}

//初始化栈
void init_stack(STACK **ps){
    (*ps)->pTop = (STACKNODE*)malloc(sizeof(STACKNODE));
    if((*ps)->pTop == NULL){
        printf("Wrong!");
        system("pause");
        exit(0);
    }
    else{
        (*ps)->pBottom = (*ps)->pTop;
        (*ps)->pTop->next = NULL;
    }
}

//去除栈顶元素使用链表返回
void push_stack(STACK **ps,Stable *pstu){
    for(int i = 0; i < pstu->rows; ++i){    
        STACKNODE *pNew = (STACKNODE*)malloc(sizeof(STACKNODE));
        if(pNew){
            pNew->data = pstu->snode->data;  
            pNew->next = (*ps)->pTop;
        }
        else{
            printf("Wrong!");
            system("pause");
            exit(0);
        }
        (*ps)->pTop = pNew;
        pstu->snode = pstu->snode->next;
    }
}

//压栈
Stable* pop_stack(STACK **ps){
    STACKNODE *p;Stable *pSTU;
    pSTU = (Stable*)malloc(sizeof(Stable));
    Slist* pre = (Slist*)malloc(sizeof(Slist));
    pSTU->cols = 3;
    pSTU->rows = 0;
    pSTU->snode = NULL;
    while(!isempty_stack(*ps)){
        p = (*ps)->pTop;
        (*ps)->pTop = p->next;

        Slist* temp = (Slist*)malloc(sizeof(Slist));
        temp->data = p->data;
        if(pSTU->snode == NULL){
            pSTU->snode = temp;
        }
        else{
            pre->next = temp;
        }
        temp->next = NULL;
        pre = temp;
        ++(pSTU->rows);

        free(p);
    }
    *ps = NULL;
    return pSTU;
}

//用栈实现逆序输出
void stack(Stable *pstu){
    STACK *stack = (STACK*)malloc(sizeof(STACK));
    Stable *pSTU;
    init_stack(&stack);                       //栈的初始化

    push_stack(&stack, pstu);           //入栈
    pSTU = pop_stack(&stack);           //元素出栈并以链表返回
    stu_output_all(pSTU);
}

bool isempty_queue(QUE *que){
    return(que->front == que->rear);
}

void init_queue(QUE **que){
    QUENODE *p = (QUENODE*)malloc(sizeof(QUENODE));
    if(p){
        (*que)->front = p;
        (*que)->rear = p;
        (*que)->len = 0;
        p->next = NULL;
    }
    else{
        printf("Wrong!");
        system("pause");
        exit(0);
    }
}

void en_queue(QUE **que,SCGtable *pscg){
    for(int i = 0; i < pscg->rows ;++i){
        QUENODE *p = (QUENODE*)malloc(sizeof(QUENODE));
        if(p){
            p->next = NULL;
            p->data = pscg->scgnode->data;
            (*que)->rear->next = p;
            (*que)->rear = p;
        }
        else{
            printf("Wrong!");
            system("pause");
            exit(0);
        }
        pscg->scgnode = pscg->scgnode->next;
    }
}

void que(SCGtable *pscg){
    QUE *que = (QUE*)malloc(sizeof(QUE));
    
    init_queue(&que);
    en_queue(&que,pscg);
    QUENODE *p = que->front;
    printf("\t\t\tINFORMATION\n----------------------------------------------------------------------\nCOURSE\t\tID\t\tNAME\t\tMAJOR\t\tSCORE\t\n");
    while(p->next){
        p = p->next;
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\n",p->data.cname,p->data.sno,p->data.sname,p->data.major,p->data.score);
    }
    printf("----------------------------------------------------------------------\n\n");
}

void menu(){
    printf("----------------------------------------------------\n");
    printf("1.Enter the students' information\n");
    printf("2.Enter the courses' information\n");
    printf("3.Enter the grades' information\n");
    printf("4.View the students' imformation\n");
    printf("5.View the courses' information\n");
    printf("6.View the grades' information\n");
    printf("7.View all information\n");
    printf("8.Search a certain course\n");
    printf("9.Check the information of failing students\n");
    printf("10.Generate new student information in reverse order\n");
    printf("11.Generate all the information using queue\n");
    printf("else:eixt\n");
    printf("----------------------------------------------------\n");
    printf("Please enter your choice: ");
}


int main(){
        Stable *pstu;
        Ctable *pcou;
        Gtable *pgra;
        SCGtable *pscg;
        while(true){
        menu();
        int choice;
        scanf("%d",&choice);
            switch (choice){
                case 1:
                stu_info_input();                       //学生信息输入
                break;

                case 2:
                cou_info_input();                           //课程信息录入
                break;
                
                case 3:
                gra_info_input(pstu,pcou);                  //成绩单信息输入
                break;

                case 4:
                stu_init(&pstu);            //学生链表初始化 
                stu_sorted(&pstu);  
                printf("\nInformation of students is shown in the table below: \n\n");
                stu_output_all(pstu);       //学生链表打印信息
                break;

                case 5:
                cou_init(&pcou);            //课程链表初始化
                cou_sorted(&pcou);
                printf("\nInformation of courses is shown in the table below: \n\n");
                cou_output_all(pcou);       //课程链表打印信息
                break;

                case 6:
                gra_init(&pgra);                            //成绩链表初始化
                gra_sno_sorted(&pgra);
                printf("\nInformation of grades is shown in the table below: \n\n");
                gra_output_all(pgra);                      //成绩链表打印信息
                break;

                case 7:
                stu_init(&pstu);                            //学生链表初始化 
                cou_init(&pcou);                            //课程链表初始化
                gra_init(&pgra);                            //成绩链表初始化
                pscg = scg_init(pstu,pcou,pgra);            //所有课程的成绩信息
                printf("\nAll information is shown in the table below: \n\n");
                scg_output_all(pscg);                       //成绩信息打印
                break;

                case 8:
                stu_init(&pstu);                            //学生链表初始化 
                cou_init(&pcou);                            //课程链表初始化
                gra_init(&pgra);                            //成绩链表初始化
                pscg = scg_init(pstu,pcou,pgra);            //所有课程的成绩信息
                printf("\nThe course's information is shown in the table below: \n\n");
                gra_stu_search(pstu,pcou,pgra);             //查询单个课程的课程信息
                break;

                case 9:
                stu_init(&pstu);                            //学生链表初始化 
                cou_init(&pcou);                            //课程链表初始化
                gra_init(&pgra);                            //成绩链表初始化
                pscg = scg_init(pstu,pcou,pgra);      //所有课程的成绩信息
                printf("\nThe course's information is shown in the table below: \n\n");
                gra_below_sixty(pscg);                      //成绩低于60名单
                break;

                case 10:
                stu_init(&pstu);                            //学生链表初始化 
                printf("\nInformation of students in reverse order is shown in the table below: \n\n");
                stack(pstu);                                //用栈逆序输出
                break;

                case 11:
                stu_init(&pstu);                            //学生链表初始化 
                cou_init(&pcou);                            //课程链表初始化
                gra_init(&pgra);                            //成绩链表初始化
                pscg = scg_init(pstu,pcou,pgra);      //所有课程的成绩信息
                printf("Information of grades is shown in the table below: \n");
                que(pscg);
                break;

                default:   exit(0);     break;
            }
            system("pause");
            system("cls");
        }
        return 0;
}
